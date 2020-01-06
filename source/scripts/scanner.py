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
dictionary = {}
for root,dirs,files in os.walk("."):
	for f in [x for x in files if x.endswith(".src")]:
		for l in [x.strip() for x in open(root+os.sep+f).readlines() if x.find(";;") >= 0]:
			m = re.match("^(.*)\\:.*?\\;\\;\\s*(.*)$",l)
			assert m is not None,f+" ... "+l
			label = m.group(1)
			elements = m.group(2).strip().lower().split()
			nElements = len(elements)
			if elements[0] not in dictionary:
				dictionary[elements[0]] = { "word":elements[0],"handler":"","encode":"",
											"decode":"", "hide":"","noexec":"" }
			entry = dictionary[elements[0]]
			if entry["handler"] == "":
				entry["handler"] = label
			for e in elements[1:]:
				if e == "encode" or e == "decode":
					assert entry[e] == "",elements[0]+"."+e+" duplicated."
					assert entry[e] != entry["handler"],elements[0]+" handler == "+e
					entry[e] = label
				elif e == "noexec" or e == "hide":
					assert entry[e] == "",elements[0]+"."+e+" set twice"
					entry[e] = "Y"
				else:
					assert False,"Bad element "+e
#
h = open("generated"+os.sep+"dictionary.inc","w")
keys = [x for x in dictionary.keys()]
keys.sort()
count = 1
for k in keys:
	e = dictionary[k]
	h.write("; *** {0} ***\n".format(k.lower()))
	h.write("\t.byte\t_end{0}-*\n".format(count))
	#
	ctrlByte = 0
	ctrlByte += (0x80 if e["hide"] == "Y" else 0x00)
	ctrlByte += (0x40 if e["noexec"] == "Y" else 0x00)
	ctrlByte += (0x02 if e["encode"] != "" else 0x00)
	ctrlByte += (0x01 if e["decode"] != "" else 0x00)
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
