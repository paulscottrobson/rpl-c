# *****************************************************************************
# *****************************************************************************
#
#		Name :		wordindex.py
#		Purpose :	Allocate each keyword a specific, final identifier ID.
#		Author :	Paul Robson (paul@robsons.org.uk)
#		Date : 		15th January 2020
#
# *****************************************************************************
# *****************************************************************************

import re

# *****************************************************************************
#
#						Create a hash mapping word to ID.
#
# *****************************************************************************

class WordIndex(object):
	def __init__(self):
		if WordIndex.INDEX is None:
			x = {}
			elements = self.raw().split("\n")
			for e in elements:
				m = re.match("^\\s*(\d+)\\s*\\:\\:\\:\\s*(.*)$",e)
				assert m is not None,"Bad line "+e
				assert m.group(2).strip() not in x,"Duplicate "+e
				x[m.group(2).strip()] = int(m.group(1))
			WordIndex.INDEX = x

	def get(self):
		return WordIndex.INDEX

# *****************************************************************************
#
#		RPL-C's word index. This is manually maintained and does not need
#		to be ordered. It does need to be consistent.
#
# *****************************************************************************

	def raw(self):
		return """
0	:::	!
1	:::	$$!handler
2	:::	$$&handler
3	:::	$$@handler
4	:::	$$call
5	:::	$$comment
6	:::	$$define
7	:::	$$literal
8	:::	$$nextline
9	:::	$$string
10	:::	*
11	:::	+
12	:::	+!
13	:::	-
14	:::	-1
15	:::	..
16	:::	/
17	:::	0
18	:::	0<
19	:::	0=
20	:::	1
21	:::	1+
22	:::	1-
23	:::	10
24	:::	100
25	:::	1024
26	:::	127
27	:::	128
28	:::	15
29	:::	16
30	:::	16*
31	:::	16/
32	:::	2
33	:::	2*
34	:::	2+
35	:::	2-
36	:::	2/
37	:::	24
38	:::	255
39	:::	256
40	:::	256*
41	:::	256/
42	:::	3
43	:::	32
44	:::	32767
45	:::	32768
46	:::	4
47	:::	4*
48	:::	4/
49	:::	4096
50	:::	5
51	:::	512
52	:::	63
53	:::	64
54	:::	8
55	:::	8*
56	:::	8/
57	:::	;
58	:::	<
59	:::	<=
60	:::	<>
61	:::	=
62	:::	>
63	:::	>=
64	:::	?dup
65	:::	@
66	:::	abs
67	:::	alloc
68	:::	and
69	:::	assert
70	:::	bswap
71	:::	c!
72	:::	c@
73	:::	clr
74	:::	drop
75	:::	dup
76	:::	else
77	:::	end
78	:::	endif
79	:::	for
80	:::	if
81	:::	index
82	:::	list
83	:::	max
84	:::	min
85	:::	mod
86	:::	negate
87	:::	new
88	:::	next
89	:::	nip
90	:::	not
91	:::	or
92	:::	over
93	:::	repeat
94	:::	rnd
95	:::	rot
96	:::	run
97	:::	sgn
98	:::	stop
99	:::	swap
100	:::	sys
101	:::	to.string
102	:::	until
103	:::	vlist
104	:::	xbreak
105	:::	xdump
106	:::	xor
107 ::: save
108 ::: load
109 ::: $$index

""".strip().upper()

WordIndex.INDEX = None		

if __name__ == "__main__":
	print(WordIndex().get())