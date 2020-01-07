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

#
#		Load Labels
#
src = [x for x in open("kernel.lbl").readlines()]
labels = {}
for s in src:
	m = re.match("^(.*)\\s*\\=\\s*\\$([0-9a-f]+)\\s*$",s)
	if m is not None:
		labels[m.group(1).lower().strip()] = int(m.group(2),16)
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
print("Hex: >>{0}".format(" ".join(["{0:7}".format(s) for s in fmt])))
fmt = ["{0}".format(c-0x10000 if (c & 0x8000) else c) for c in stack]
print("Dec: >>{0}".format(" ".join(["{0:7}".format(s) for s in fmt])))
