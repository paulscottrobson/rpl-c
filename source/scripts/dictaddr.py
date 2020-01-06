# *****************************************************************************
# *****************************************************************************
#
#		Name :		dictaddr.py
#		Purpose :	Dictionary which has the actual addresses which are
#					extracted from the kernel label file.
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		6th January 2020
#
# *****************************************************************************
# *****************************************************************************

import os,sys,re
from scanner import *

# *****************************************************************************
#
#	   Dictionary with information about each system word including address
#
# *****************************************************************************

class DictionaryFull(Dictionary):
	#
	#		Create and initialise dictionary.
	#
	def __init__(self):
		Dictionary.__init__(self)
		self.readLabels()
		self.updateEntries()
	#
	#		Read the labels in from kernel.lbl
	#
	def readLabels(self):
		self.labels = {}
		for s in [x.strip() for x in open("kernel.lbl").readlines() if x.strip() != ""]:
			m = re.match("^(.*?)\\s*\\=\\s*(\\$?[0-9a-f]+)$",s)
			assert m is not None,"Bad line "+s
			self.labels[m.group(1)] = int(m.group(2)[1:],16) if m.group(2).startswith("$") else int(m.group(2))
	#
	#		Put the values of the labels in the dictionary.
	#
	def updateEntries(self):
		for k in self.getKeys():
			entry = self.get(k)
			assert entry["handler"] in self.labels,"No handler label for "+k
			entry["address"] = self.labels[entry["handler"]]
	#
	#		Get execution address for given word.
	#
	def getAddress(self,word):
		return self.get(word)["address"]
#
#		Just shows the entries, test.
#
if __name__ == "__main__":
	d = DictionaryFull()
	for k in d.getKeys():
		print("{0:14} {1:14} = ${2:04x}".format(k,d.get(k)["handler"]+":",d.get(k)["address"]))
