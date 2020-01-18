# *****************************************************************************
# *****************************************************************************
#
#		Name :		encdectest.py
#		Purpose :	Generate code for testing
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		6th January 2020
#
# *****************************************************************************
# *****************************************************************************

import os,random
from scanner import *
from rplconv import *
#
#		Create an alpha/alphanumeric
#
def rChar(aOnly):
	c = random.randint(65,90)
	if not aOnly and random.randint(0,2) == 0:
		c = random.randint(48,57)
	return c
#
#		Create an identifier
#
def getIdentifier(s1,s2):
	return "".join([chr(rChar(x == 0)) for x in range(0,s1+random.randint(0,s2-s1))])

#
#		Names of keywords
#
names = [x.upper() for x in Dictionary().getKeys()]
#
#		Select a test
#
random.seed()
seed = random.randint(0,10000)
#seed = 6108
print("seed ",seed)
random.seed(seed)
l = random.randint(1,64000)
s = [str(l)]
#
#		Create some procedure names
#
callers = [getIdentifier(2,8).upper() for x in range(0,15)]
#
#		Create a program which is just :<callers> ;
#
prg = RPLProgram()
for c in callers:
	prg.addLine(":{0} ;".format(c))
prg.convert(LineConverter())
h = open("generated"+os.sep+"rplcode.bin","wb")
h.write(bytes(prg.code))
h.close()
#
#		Create an encodable string
#
structs = "IF/ENDIF,IF ELSE/ENDIF,IF/ELSE ENDIF,REPEAT/UNTIL,FOR/NEXT".split(",")

doneRem = False
while len(" ".join(s)) < 220 and not doneRem:
	n = random.randint(0,6)
	#
	#	Keywords (0)
	#
	if n == 0:
		name = names[random.randint(0,len(names)-1)].upper()
		if not name.startswith("$$") and not name in ["IF","ELSE","ENDIF","REPEAT","UNTIL","FOR","NEXT"]:
			s.append(name)
	#			
	# 	Comments and strings (1)
	#
	if n == 1:
		st = getIdentifier(3,9) if random.randint(0,9) > 0 else ""
		if random.randint(0,10) == 0:
			s.append("' "+st) 
			doneRem = True
		else:
			s.append('"'+st+'"')
	#
	#	Defined Routines (2)
	#
	if n == 2:
		s.append(callers[random.randint(0,len(callers)-1)])
	#
	#	Constants (3)
	#
	if n == 3:
		v = random.randint(-32768,32767)
		s.append(str(v))
	#
	#	Direct calls (4)
	#
	if n == 4:
		v = random.randint(30000,40000)			# obviously not having :definitions
		s.append("<"+str(v)+">")
	#
	#	Variable access (5)
	#
	if n == 5:
		v = "&!@"[random.randint(0,2)]+getIdentifier(1,3)
		s.append(v)
	#
	#	Structures (6)
	#
	if n == 6:
		v = structs[random.randint(0,len(structs)-1)].split("/")
		s.insert(1,v[0])
		s.append(v[1])
#
#		Output it to an include file.
#
s = " ".join(s).strip().upper()
s = s + (" " * random.randint(0,5))
print(s)
s = s + chr(0)
h = open("generated"+os.sep+"edtext.inc","w")
h.write("\t.byte {0}\n".format(",".join(["${0:02x}".format(ord(c)) for c in s])))
h.close()
