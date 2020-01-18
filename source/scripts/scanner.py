# *****************************************************************************
# *****************************************************************************
#
#		Name :		scanner.py
#		Purpose :	Scan source files for system words
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		6th January 2020
#
# *****************************************************************************
# *****************************************************************************

import os,sys,re
from wordindex import *

# *****************************************************************************
#
#				Dictionary with information about each system word
#
# *****************************************************************************

class Dictionary(object):
	#
	#		Create and initialise dictionary.
	#
	def __init__(self):
		self.dictionary = {}
		for root,dirs,files in os.walk("."):								# scan for lines
			for f in [x for x in files if x.endswith(".src")]:
				for l in [x.strip() for x in open(root+os.sep+f).readlines() if x.find(";;") >= 0]:
					if l.find(";;;") < 0:
						m = re.match("^(.*)\\:.*?\\;\\;\\s*(.*)$",l)
						assert m is not None,f+" ... "+l
						self.append(m.group(2).strip().lower().split(),m.group(1))
		self.index = WordIndex().get()										# get the index.					
	#					
	#		Add a <label>: .... ;; <elements> reference
	#
	def append(self,elements,label):					
		nElements = len(elements)
		if elements[0] not in self.dictionary:								# create record
			self.dictionary[elements[0]] = { "word":elements[0],"handler":"","encode":"","params":"",
					 						 "decode":"", "hide":"","noexec":"" }
		entry = self.dictionary[elements[0]]								# add label if required
		if entry["handler"] == "":
			entry["handler"] = label
		for e in elements[1:]:												# process the rest
			if e == "encode" or e == "decode":								# handle types
				assert entry[e] == "",elements[0]+"."+e+" duplicated."
				assert entry[e] != entry["handler"],elements[0]+" handler == "+e
				entry[e] = label
			elif e == "noexec" or e == "hide":								# handle switches
				assert entry[e] == "",elements[0]+"."+e+" set twice"
				entry[e] = "Y"
			elif e.startswith("<") and e.endswith(">") and "012n".find(e[1]) >= 0:
				entry["params"] = e[1]
			else:															# unknown
				assert False,"Bad element "+e
	#
	#		Get all the keys sorted
	#
	def getKeys(self):
		keys = [x for x in self.dictionary.keys()]
		assert len(keys) == len(self.index.keys()),"Wordindex keys and code keys do not match"
		keys.sort(key = lambda x:self.index[x.upper()])
		return keys
	#
	#		Does a word exist
	#
	def isWord(self,key):
		key = key.strip().lower()
		return key in self.dictionary
	#
	#		Get a specific record.
	#
	def get(self,key):
		key = key.strip().lower()
		assert key in self.dictionary,"Unknown "+key
		return self.dictionary[key]
#
#		This creates the dictionary include file.
#
if __name__ == "__main__":
	d = Dictionary()
	h = open("generated"+os.sep+"dictionary.inc","w")
	count = 0
	keys = d.getKeys()
	for k in keys:
		e = d.get(k)
		h.write("; *** {0} [ID:{1}] ***\n".format(k.lower(),d.index[k.upper()]))
		h.write("\t.byte\t_end{0}-*\n".format(count))
		#
		ctrlByte ="012n".find(e["params"])
		assert ctrlByte >= 0,"Not defined params "+k
		ctrlByte += (0x80 if e["hide"] == "Y" else 0x00)
		ctrlByte += (0x40 if e["noexec"] == "Y" else 0x00)
		ctrlByte += (0x20 if e["encode"] != "" else 0x00)
		ctrlByte += (0x10 if e["decode"] != "" else 0x00)
		h.write("\t.byte\t${0:02x}\n".format(ctrlByte))
		#
		h.write("\t.word\t{0}\n".format(e["handler"]))
		if e["decode"] != "":
			h.write("\t.word\t{0}\n".format(e["decode"]))
		if e["encode"] != "":
			h.write("\t.word\t{0}\n".format(e["encode"]))
		#
		bs = [ord(c) for c in k.upper()]
		bs[-1] |= 0x80
		h.write("\t.byte\t{0}\n".format(",".join(["${0:02x}".format(c) for c in bs])))
		#
		h.write("_end{0}:\n\n".format(count))
		count += 1
	h.write("\t.byte\t0\n\n")
	h.close()
