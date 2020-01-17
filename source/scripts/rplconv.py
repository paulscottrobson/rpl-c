# *****************************************************************************
# *****************************************************************************
#
#		Name :		rplconv.py
#		Purpose :	Convert the RPL text code to tokenised equivalent
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		7th January 2020
#
# *****************************************************************************
# *****************************************************************************
 
import re,os
from dictaddr import *

# *****************************************************************************
#
#								RPL Program Class
#
# *****************************************************************************

class RPLProgram(object):
	def __init__(self):
		self.firstLine = 1000
		self.lineStep = 10
		self.lines = []
	#
	#		Add a file
	#
	def addFile(self,srcFile):
		src = [x.replace("\t"," ").upper().strip() for x in open(srcFile).readlines() if x.strip() != ""]
		self.lines += src
	#
	#		Add a line
	#
	def addLine(self,l):
		l = l.strip()
		if l != "":
			self.lines.append(l)
	#
	#		Convert a file
	#
	def convert(self,convertObject):
		self.analyseDefinitions()
		self.code = []
		for i in range(0,len(self.lines)):
			#print(">>> {0:5} {1}".format(self.getLineNumber(i),self.lines[i]))
			lineCode = convertObject.convertLine(self.lines[i],self)
			lineNumber = self.getLineNumber(i)
			lineCode = [ 3+len(lineCode), lineNumber & 0xFF,lineNumber >> 8] + lineCode
			#print(" ".join(["{0:02x}".format(c) for c in lineCode]))
			self.code += lineCode
		self.code.append(0)
	#
	#		Look for definitions.
	#
	def analyseDefinitions(self):
		self.definitions = {}
		for i in range(0,len(self.lines)):
			m = re.match("^\\:([A-Z0-9\\.]+)",self.lines[i])
			if m is not None:
				assert m.group(1) not in self.definitions,"Duplicate "+m.group(1)
				self.definitions[m.group(1)] = self.getLineNumber(i)
	#
	#		Get a line number
	#
	def getLineNumber(self,n):
		return self.firstLine + self.lineStep * n
	#
	#		See if a definition exists, return line# or None
	#
	def findDefinition(self,word):
		word = word.strip().upper()
		return self.definitions[word] if word in self.definitions else None

# *****************************************************************************
#
#						Class that encodes a single line
#
# *****************************************************************************

class ConversionException(Exception):
	pass

class LineConverter(object):
	def __init__(self):
		self.rplDictionary = DictionaryFull()		
	#
	#		Convert a line
	#
	def convertLine(self,line,parent):
		self.code = []														# result here
		self.rStack = [ 0 ]													# Structure stack.
		self.parent = parent												# who to ask about defines
		line = line.upper().strip()											# preprocess
		while line != "":													# keep doing till all gone
			line = self.convertElement(line).strip()
		self.appendWord("$$nextline")										# end of line marker
		if len(self.rStack) != 1:											# unclosed structure ?
			raise ConversionException("Structure open")
		return self.code 
	#
	#		Convert a single element
	#
	def convertElement(self,e):
		#
		#		Firstly, the two elements which are not word orientated - these are
		#		' <comment to end of line and "string to next quote"
		#
		if e.startswith("'"):												# ' <comment>
			self.appendWord("$$comment")									# comment handler
			e = e[1:].strip()
			self.code.append(len(e)+1)										# length of comment + len
			self.code += [ord(c) for c in e]								# comment
			return ""
		#
		if e.startswith('"'):												# "<string>"
			m = re.match('^\"(.*?)\"(.*)$',e)								# split up
			if m is None:				
				raise ConversionException("Bad String "+e)
			self.appendWord("$$string")										# string handler
			self.code.append(len(m.group(1))+2)								# strlen + len + null
			self.code += [ord(c) for c in m.group(1)]						# add string
			self.code.append(0)												# make ASCIIZ
			return m.group(2)
		#
		#		Word orientated. Split the word off and analyse it. First is it in the
		#		dictionary. Second is it a call of a definition. Third is it a constant (dec/hex)
		#		Fourth, is it a colon definition, Fifth, is it variable access.
		#
		p = (e+" ").find(" ")												# split off a word
		word = e[:p]
		nextCode = e[p:].strip()
		#
		if word == "REPEAT" or word == "UNTIL":								# repeat/until 
			self.repeatUntil(word)
			return nextCode
		if word == "FOR" or word == "NEXT":									# for/next
			self.forNext(word)
			return nextCode
		if word == "IF" or word == "ELSE" or word == "ENDIF":				# if/else/endif
			self.ifElseEndif(word)
			return nextCode
		#
		if self.rplDictionary.isWord(word):									# is it a known word
			self.appendWord(word) 											# (e.g. a dictionary word)
			return nextCode
		#
		lineNumber = self.parent.findDefinition(word)						# is it a definition call ?
		if lineNumber is not None:											
			self.appendWord("$$call")										# call that line number.
			self.code.append(lineNumber & 0xFF)
			self.code.append(lineNumber >> 8)
			return nextCode
		#
		m1 = re.match("^\\-?\\d+$",word)									# try decimal/hexadecimal
		m2 = re.match("^\\$([0-9A-F]+)$",word)
		if m1 is not None or m2 is not None:								# either
			self.appendWord("$$hexliteral" if word[0]=="$" else "$$literal")# literal handler
			n = int(word) if m1 is not None else int(word[1:],16)			# convert to integer
			self.code.append(n & 0xFF)										# append in range
			self.code.append((n & 0xFFFF) >> 8)
			return nextCode
		#
		if re.match("^\\:[A-Z][A-Z0-9\\.]*$",word) is not None:				# :definition
			self.appendWord("$$define")										# define handler
			self.code.append(len(word))										# remove : add length
			wByte = [ord(c) for c in word[1:]]								# convert to bytes
			wByte[-1] += 0x80												# set bit 7 of last.
			self.code += wByte
			return nextCode
		#		
		m = re.match("^[\\@\\!\\&]([A-Z][A-Z0-9]*)(.*)$",word) 				# is it @var !var &var
		if m is not None:
			if len(m.group(1)) > 3:
				raise ConversionException("Variable too long "+word)
			name = m.group(1)+"  "											# pad name out.
			nameEnc = self.getCh(name[0])+self.getCh(name[1])*32+self.getCh(name[2])*32*40
			self.appendWord("$$"+word[0]+"handler")
			self.code.append(nameEnc & 0xFF)
			self.code.append(nameEnc >> 8)
			if m.group(2) != "":											# index ?
				m2 = re.match("^\\[\\d+\\]$",m.group(2))
				if m2 is None:
					raise ConversionException("Bad variable name "+word)
				self.appendWord("$$index")
				self.code.append(int(m.group(2)[1:-1]))
			return nextCode
		#
		raise ConversionException("Can't process "+word)
	#
	#		Convert character to value
	#
	def getCh(self,c):
		if c == ' ':
			return 0
		if c >= 'A' and c <= 'Z':
			return ord(c)-ord('A')+1
		if c >= '0' and c <= '9':
			return int(c)+27
		assert False
	#
	#		Append the handler address of the given word.
	#
	def appendWord(self,name):
		addr = self.rplDictionary.getAddress(name)
		self.code.append(addr & 0xFF)
		self.code.append(addr >> 8)
	#
	#		Current code position in line
	#
	def currentPos(self):
		return len(self.code)
	#
	#		Check pop stack for structure mixing
	#
	def checkPop(self,required):
		if self.rStack.pop() != required:
			raise ConversionException("Structures mixed")
	#
	#		Handle repeat/until
	#
	def repeatUntil(self,word):
		#
		if word == "REPEAT":												# REPEAT
			self.appendWord("REPEAT")										# Compile dummy repeat
			self.rStack.append(self.currentPos())							# Save loop address
			self.rStack.append(LineConverter.REPEAT)						# Save repeat marker
		#
		if word == "UNTIL":
			self.checkPop(LineConverter.REPEAT)								# convertor ?
			self.appendWord("UNTIL")										# Loop action
			self.code.append(self.rStack.pop()+3)							# branch back X value
	#
	#		Handle for/next
	#
	def forNext(self,word):
		#
		if word == "FOR":													# For
			self.appendWord("FOR")											# Compile for (n->r)
			self.rStack.append(self.currentPos())							# Save loop address
			self.rStack.append(LineConverter.FOR)							# Save for marker
		#
		if word == "NEXT":
			self.checkPop(LineConverter.FOR)								# convertor ?
			self.appendWord("NEXT")											# Loop action
			self.code.append(self.rStack.pop()+3)							# branch back X value
	#
	#		Handle if/else/endif
	#
	def ifElseEndif(self,word):
		#
		if word == "IF":
			self.appendWord("IF")											# if (branch if zero)
			self.rStack.append(self.currentPos())							# save branch pos
			self.rStack.append(LineConverter.IF)							# save IF marker
			self.code.append(0)												# dummy branch.

		if word == "ELSE":													# else (branch always)
			self.checkPop(LineConverter.IF)									# check it was an if
			self.appendWord("ELSE")											# branch out.
			elseBranch = self.currentPos()									# branch out patch.
			self.code.append(0)												# dummy branch
			self.code[self.rStack.pop()] = self.currentPos()+3 				# back-patch if.
			self.rStack.append(elseBranch)									# patch this later
			self.rStack.append(LineConverter.IF)							# save IF marker

		if word == "ENDIF":
			self.checkPop(LineConverter.IF)									# check it was an if
			self.appendWord("ENDIF")										# marker
			self.code[self.rStack.pop()] = self.currentPos()+3 				# back-patch if.


LineConverter.REPEAT = 'R'
LineConverter.FOR = 'F'
LineConverter.IF = 'I'

if __name__ == "__main__":
	prg = RPLProgram()
	prg.addFile("rpl/test.rpl")
	prg.convert(LineConverter())
	open("generated"+os.sep+"rplcode.bin","wb").write(bytes(prg.code))
