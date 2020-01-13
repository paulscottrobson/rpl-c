# *****************************************************************************
# *****************************************************************************
#
#		Name :		check.py
#		Purpose :	Check encode/decode worked.
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		6th January 2020
#
# *****************************************************************************
# *****************************************************************************

import re,os,sys

def readString(p):
	s = ""
	while mem[p] != 0:
		c = mem[p] & 0x7F
		c = c if c >= 32 else 32
		s += chr(c)
		p += 1
	s = s.upper().strip()
	while s.find("  ") >= 0:
		s = s.replace("  "," ")
	return s
#
#		Load Labels
#
src = [x for x in open("kernel.lbl").readlines()]
labels = {}
for s in src:
	m = re.match("^(.*)\\s*\\=\\s*(\\$?[0-9a-f]+)\\s*$",s)
	assert m is not None,s
	labels[m.group(1).lower().strip()] = int(m.group(2)[1:],16) if m.group(2).startswith("$") else int(m.group(2))
#
#		Information dump
#
mem = [x for x in open("dump.bin","rb").read(-1)]
sp = mem[labels["temp1"]]
#
tosAddr = labels["tos"]
stack = [ mem[tosAddr]+mem[tosAddr+1]*256 ]
for i in range(sp,labels["numberstackbase"]-2,2):
	stack.append(mem[0x102+i]+mem[0x101+i]*256)

s1 = readString(labels["encodetestlineoriginal"])
s2 = readString(labels["textbuffer"])
print("Org",s1)
print("Dec",s2)
if s1 != s2:
	print("Error")
	while True:
		pass
sys.exit(0)	