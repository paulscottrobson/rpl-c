# *****************************************************************************
# *****************************************************************************
#
#		Name :		show.py
#		Purpose :	Dump the data stack.
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		6th January 2020
#
# *****************************************************************************
# *****************************************************************************

import re

def cv(n):
	n = int(n) % 40
	if n == 0:
		return "."
	if n <= 26:
		return chr(n+96)
	return(chr(n-27+48))
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
for i in range(sp,253,2):
	stack.append(mem[0x102+i]+mem[0x101+i]*256)

fmt = ["${0:04x}".format(c) for c in stack]
print("Hex:\n{0}".format("\n".join(["\t{0:7}".format(s) for s in fmt])))
fmt = ["{0}".format(c-0x10000 if (c & 0x8000) else c) for c in stack]
print("Dec:\n{0}".format("\n".join(["\t{0:7}".format(s) for s in fmt])))

print("Fixed:")
azv = labels["azvariables"]
for i in range(1,27):
	v = mem[azv+i*2]+mem[azv+i*2+1]*256
	v = v-0x10000 if (v & 0x8000) else v
	if v != 0:
		print("{0} := {1} ${2:04x}".format(chr(i+96),v,v & 0xFFFF))

print("Hash:")	
htBase = labels["hashtable"]
for ht in range(0,labels["hashtablesize"]):
	link = mem[htBase+ht*2]+mem[htBase+ht*2+1]*256
	while link != 0:
		n = mem[link+4]+mem[link+5]*256
		name = cv(n & 31)+cv(n/32)+cv(n/32/40)
		n = mem[link+2]+mem[link+3]*256
		print("#{0:2} {1} := {2} ${3:04x}".format(ht,name,n-0x10000 if (n & 0x8000) else n,n))

		link = mem[link+0]+mem[link+1]*256
