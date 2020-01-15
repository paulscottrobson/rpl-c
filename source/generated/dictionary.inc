; *** ! [ID:0] ***
	.byte	_end0-*
	.byte	$00
	.word	WordWrite
	.byte	$a1
_end0:

; *** $$!handler [ID:1] ***
	.byte	_end1-*
	.byte	$52
	.word	VarWriteHandler
	.word	VarWriteHandlerDecode
	.byte	$24,$24,$21,$48,$41,$4e,$44,$4c,$45,$d2
_end1:

; *** $$&handler [ID:2] ***
	.byte	_end2-*
	.byte	$52
	.word	VarAddressHandler
	.word	VarAddrHandlerDecode
	.byte	$24,$24,$26,$48,$41,$4e,$44,$4c,$45,$d2
_end2:

; *** $$@handler [ID:3] ***
	.byte	_end3-*
	.byte	$52
	.word	VarReadHandler
	.word	VarReadHandlerDecode
	.byte	$24,$24,$40,$48,$41,$4e,$44,$4c,$45,$d2
_end3:

; *** $$call [ID:4] ***
	.byte	_end4-*
	.byte	$52
	.word	CallHandler
	.word	CallHandlerDecode
	.byte	$24,$24,$43,$41,$4c,$cc
_end4:

; *** $$comment [ID:5] ***
	.byte	_end5-*
	.byte	$53
	.word	SkipComment
	.word	CommentDecoder
	.byte	$24,$24,$43,$4f,$4d,$4d,$45,$4e,$d4
_end5:

; *** $$define [ID:6] ***
	.byte	_end6-*
	.byte	$53
	.word	DefineCode
	.word	DefineDecoder
	.byte	$24,$24,$44,$45,$46,$49,$4e,$c5
_end6:

; *** $$literal [ID:7] ***
	.byte	_end7-*
	.byte	$52
	.word	Literal2Byte
	.word	Literal2ByteDecode
	.byte	$24,$24,$4c,$49,$54,$45,$52,$41,$cc
_end7:

; *** $$nextline [ID:8] ***
	.byte	_end8-*
	.byte	$80
	.word	NextLine
	.byte	$24,$24,$4e,$45,$58,$54,$4c,$49,$4e,$c5
_end8:

; *** $$string [ID:9] ***
	.byte	_end9-*
	.byte	$53
	.word	LiteralString
	.word	LiteralStringDecoder
	.byte	$24,$24,$53,$54,$52,$49,$4e,$c7
_end9:

; *** * [ID:10] ***
	.byte	_end10-*
	.byte	$00
	.word	Multiply16x16
	.byte	$aa
_end10:

; *** + [ID:11] ***
	.byte	_end11-*
	.byte	$00
	.word	Add
	.byte	$ab
_end11:

; *** +! [ID:12] ***
	.byte	_end12-*
	.byte	$00
	.word	WordAdd
	.byte	$2b,$a1
_end12:

; *** - [ID:13] ***
	.byte	_end13-*
	.byte	$00
	.word	Subtract
	.byte	$ad
_end13:

; *** -1 [ID:14] ***
	.byte	_end14-*
	.byte	$00
	.word	ConstantMinus1
	.byte	$2d,$b1
_end14:

; *** .. [ID:15] ***
	.byte	_end15-*
	.byte	$00
	.word	DumpStack
	.byte	$2e,$ae
_end15:

; *** / [ID:16] ***
	.byte	_end16-*
	.byte	$00
	.word	Divide16x16
	.byte	$af
_end16:

; *** 0 [ID:17] ***
	.byte	_end17-*
	.byte	$00
	.word	Constant0
	.byte	$b0
_end17:

; *** 0< [ID:18] ***
	.byte	_end18-*
	.byte	$00
	.word	CheckMinus
	.byte	$30,$bc
_end18:

; *** 0= [ID:19] ***
	.byte	_end19-*
	.byte	$00
	.word	CheckZero
	.byte	$30,$bd
_end19:

; *** 1 [ID:20] ***
	.byte	_end20-*
	.byte	$00
	.word	C1
	.byte	$b1
_end20:

; *** 1+ [ID:21] ***
	.byte	_end21-*
	.byte	$00
	.word	Unary1Plus
	.byte	$31,$ab
_end21:

; *** 1- [ID:22] ***
	.byte	_end22-*
	.byte	$00
	.word	Unary1Minus
	.byte	$31,$ad
_end22:

; *** 10 [ID:23] ***
	.byte	_end23-*
	.byte	$00
	.word	C10
	.byte	$31,$b0
_end23:

; *** 100 [ID:24] ***
	.byte	_end24-*
	.byte	$00
	.word	C100
	.byte	$31,$30,$b0
_end24:

; *** 1024 [ID:25] ***
	.byte	_end25-*
	.byte	$00
	.word	C1024
	.byte	$31,$30,$32,$b4
_end25:

; *** 127 [ID:26] ***
	.byte	_end26-*
	.byte	$00
	.word	C127
	.byte	$31,$32,$b7
_end26:

; *** 128 [ID:27] ***
	.byte	_end27-*
	.byte	$00
	.word	C128
	.byte	$31,$32,$b8
_end27:

; *** 15 [ID:28] ***
	.byte	_end28-*
	.byte	$00
	.word	C15
	.byte	$31,$b5
_end28:

; *** 16 [ID:29] ***
	.byte	_end29-*
	.byte	$00
	.word	C16
	.byte	$31,$b6
_end29:

; *** 16* [ID:30] ***
	.byte	_end30-*
	.byte	$00
	.word	Times16
	.byte	$31,$36,$aa
_end30:

; *** 16/ [ID:31] ***
	.byte	_end31-*
	.byte	$00
	.word	Divide16
	.byte	$31,$36,$af
_end31:

; *** 2 [ID:32] ***
	.byte	_end32-*
	.byte	$00
	.word	C2
	.byte	$b2
_end32:

; *** 2* [ID:33] ***
	.byte	_end33-*
	.byte	$00
	.word	Times2
	.byte	$32,$aa
_end33:

; *** 2+ [ID:34] ***
	.byte	_end34-*
	.byte	$00
	.word	Unary2Plus
	.byte	$32,$ab
_end34:

; *** 2- [ID:35] ***
	.byte	_end35-*
	.byte	$00
	.word	Unary2Minus
	.byte	$32,$ad
_end35:

; *** 2/ [ID:36] ***
	.byte	_end36-*
	.byte	$00
	.word	Divide2
	.byte	$32,$af
_end36:

; *** 24 [ID:37] ***
	.byte	_end37-*
	.byte	$00
	.word	C24
	.byte	$32,$b4
_end37:

; *** 255 [ID:38] ***
	.byte	_end38-*
	.byte	$00
	.word	C255
	.byte	$32,$35,$b5
_end38:

; *** 256 [ID:39] ***
	.byte	_end39-*
	.byte	$00
	.word	C256
	.byte	$32,$35,$b6
_end39:

; *** 256* [ID:40] ***
	.byte	_end40-*
	.byte	$00
	.word	Times256
	.byte	$32,$35,$36,$aa
_end40:

; *** 256/ [ID:41] ***
	.byte	_end41-*
	.byte	$00
	.word	Divide256
	.byte	$32,$35,$36,$af
_end41:

; *** 3 [ID:42] ***
	.byte	_end42-*
	.byte	$00
	.word	C3
	.byte	$b3
_end42:

; *** 32 [ID:43] ***
	.byte	_end43-*
	.byte	$00
	.word	C32
	.byte	$33,$b2
_end43:

; *** 32767 [ID:44] ***
	.byte	_end44-*
	.byte	$00
	.word	C32767
	.byte	$33,$32,$37,$36,$b7
_end44:

; *** 32768 [ID:45] ***
	.byte	_end45-*
	.byte	$00
	.word	C32768
	.byte	$33,$32,$37,$36,$b8
_end45:

; *** 4 [ID:46] ***
	.byte	_end46-*
	.byte	$00
	.word	C4
	.byte	$b4
_end46:

; *** 4* [ID:47] ***
	.byte	_end47-*
	.byte	$00
	.word	Times4
	.byte	$34,$aa
_end47:

; *** 4/ [ID:48] ***
	.byte	_end48-*
	.byte	$00
	.word	Divide4
	.byte	$34,$af
_end48:

; *** 4096 [ID:49] ***
	.byte	_end49-*
	.byte	$00
	.word	C4096
	.byte	$34,$30,$39,$b6
_end49:

; *** 5 [ID:50] ***
	.byte	_end50-*
	.byte	$00
	.word	C5
	.byte	$b5
_end50:

; *** 512 [ID:51] ***
	.byte	_end51-*
	.byte	$00
	.word	C512
	.byte	$35,$31,$b2
_end51:

; *** 63 [ID:52] ***
	.byte	_end52-*
	.byte	$00
	.word	C63
	.byte	$36,$b3
_end52:

; *** 64 [ID:53] ***
	.byte	_end53-*
	.byte	$00
	.word	C64
	.byte	$36,$b4
_end53:

; *** 8 [ID:54] ***
	.byte	_end54-*
	.byte	$00
	.word	C8
	.byte	$b8
_end54:

; *** 8* [ID:55] ***
	.byte	_end55-*
	.byte	$00
	.word	Times8
	.byte	$38,$aa
_end55:

; *** 8/ [ID:56] ***
	.byte	_end56-*
	.byte	$00
	.word	Divide8
	.byte	$38,$af
_end56:

; *** ; [ID:57] ***
	.byte	_end57-*
	.byte	$40
	.word	ReturnHandler
	.byte	$bb
_end57:

; *** < [ID:58] ***
	.byte	_end58-*
	.byte	$00
	.word	CheckLess
	.byte	$bc
_end58:

; *** <= [ID:59] ***
	.byte	_end59-*
	.byte	$00
	.word	CheckLessEq
	.byte	$3c,$bd
_end59:

; *** <> [ID:60] ***
	.byte	_end60-*
	.byte	$00
	.word	CheckNotEqual
	.byte	$3c,$be
_end60:

; *** = [ID:61] ***
	.byte	_end61-*
	.byte	$00
	.word	CheckEqual
	.byte	$bd
_end61:

; *** > [ID:62] ***
	.byte	_end62-*
	.byte	$00
	.word	CheckGreater
	.byte	$be
_end62:

; *** >= [ID:63] ***
	.byte	_end63-*
	.byte	$00
	.word	CheckGreaterEq
	.byte	$3e,$bd
_end63:

; *** ?dup [ID:64] ***
	.byte	_end64-*
	.byte	$00
	.word	TestDup
	.byte	$3f,$44,$55,$d0
_end64:

; *** @ [ID:65] ***
	.byte	_end65-*
	.byte	$00
	.word	WordRead
	.byte	$c0
_end65:

; *** abs [ID:66] ***
	.byte	_end66-*
	.byte	$00
	.word	Absolute
	.byte	$41,$42,$d3
_end66:

; *** alloc [ID:67] ***
	.byte	_end67-*
	.byte	$00
	.word	AllocateMemory
	.byte	$41,$4c,$4c,$4f,$c3
_end67:

; *** and [ID:68] ***
	.byte	_end68-*
	.byte	$00
	.word	And
	.byte	$41,$4e,$c4
_end68:

; *** assert [ID:69] ***
	.byte	_end69-*
	.byte	$00
	.word	AssertCode
	.byte	$41,$53,$53,$45,$52,$d4
_end69:

; *** bswap [ID:70] ***
	.byte	_end70-*
	.byte	$00
	.word	ByteSwap
	.byte	$42,$53,$57,$41,$d0
_end70:

; *** c! [ID:71] ***
	.byte	_end71-*
	.byte	$00
	.word	ByteWrite
	.byte	$43,$a1
_end71:

; *** c@ [ID:72] ***
	.byte	_end72-*
	.byte	$00
	.word	ByteRead
	.byte	$43,$c0
_end72:

; *** clr [ID:73] ***
	.byte	_end73-*
	.byte	$00
	.word	ClrHandler
	.byte	$43,$4c,$d2
_end73:

; *** drop [ID:74] ***
	.byte	_end74-*
	.byte	$00
	.word	Drop
	.byte	$44,$52,$4f,$d0
_end74:

; *** dup [ID:75] ***
	.byte	_end75-*
	.byte	$00
	.word	Dup
	.byte	$44,$55,$d0
_end75:

; *** else [ID:76] ***
	.byte	_end76-*
	.byte	$21
	.word	ElseHandler
	.word	ElseEncoder
	.byte	$45,$4c,$53,$c5
_end76:

; *** end [ID:77] ***
	.byte	_end77-*
	.byte	$00
	.word	EndProgram
	.byte	$45,$4e,$c4
_end77:

; *** endif [ID:78] ***
	.byte	_end78-*
	.byte	$20
	.word	EndIfHandler
	.word	EndIfEncoder
	.byte	$45,$4e,$44,$49,$c6
_end78:

; *** for [ID:79] ***
	.byte	_end79-*
	.byte	$20
	.word	ForHandler
	.word	ForEncoder
	.byte	$46,$4f,$d2
_end79:

; *** if [ID:80] ***
	.byte	_end80-*
	.byte	$21
	.word	IfHandler
	.word	IfEncoder
	.byte	$49,$c6
_end80:

; *** index [ID:81] ***
	.byte	_end81-*
	.byte	$00
	.word	GetIndex
	.byte	$49,$4e,$44,$45,$d8
_end81:

; *** list [ID:82] ***
	.byte	_end82-*
	.byte	$00
	.word	ListCode
	.byte	$4c,$49,$53,$d4
_end82:

; *** max [ID:83] ***
	.byte	_end83-*
	.byte	$00
	.word	Maximum
	.byte	$4d,$41,$d8
_end83:

; *** min [ID:84] ***
	.byte	_end84-*
	.byte	$00
	.word	Minimum
	.byte	$4d,$49,$ce
_end84:

; *** mod [ID:85] ***
	.byte	_end85-*
	.byte	$00
	.word	Modulus16x16
	.byte	$4d,$4f,$c4
_end85:

; *** negate [ID:86] ***
	.byte	_end86-*
	.byte	$00
	.word	Negate
	.byte	$4e,$45,$47,$41,$54,$c5
_end86:

; *** new [ID:87] ***
	.byte	_end87-*
	.byte	$00
	.word	NewHandler
	.byte	$4e,$45,$d7
_end87:

; *** next [ID:88] ***
	.byte	_end88-*
	.byte	$21
	.word	NextHandler
	.word	NextEncoder
	.byte	$4e,$45,$58,$d4
_end88:

; *** nip [ID:89] ***
	.byte	_end89-*
	.byte	$00
	.word	Nip
	.byte	$4e,$49,$d0
_end89:

; *** not [ID:90] ***
	.byte	_end90-*
	.byte	$00
	.word	OneComplement
	.byte	$4e,$4f,$d4
_end90:

; *** or [ID:91] ***
	.byte	_end91-*
	.byte	$00
	.word	LogOr
	.byte	$4f,$d2
_end91:

; *** over [ID:92] ***
	.byte	_end92-*
	.byte	$00
	.word	Over
	.byte	$4f,$56,$45,$d2
_end92:

; *** repeat [ID:93] ***
	.byte	_end93-*
	.byte	$20
	.word	RepeatHandler
	.word	RepeatEncoder
	.byte	$52,$45,$50,$45,$41,$d4
_end93:

; *** rnd [ID:94] ***
	.byte	_end94-*
	.byte	$00
	.word	RandomNumber
	.byte	$52,$4e,$c4
_end94:

; *** rot [ID:95] ***
	.byte	_end95-*
	.byte	$00
	.word	Rot
	.byte	$52,$4f,$d4
_end95:

; *** run [ID:96] ***
	.byte	_end96-*
	.byte	$00
	.word	RunProgram
	.byte	$52,$55,$ce
_end96:

; *** sgn [ID:97] ***
	.byte	_end97-*
	.byte	$00
	.word	SignTOS
	.byte	$53,$47,$ce
_end97:

; *** stop [ID:98] ***
	.byte	_end98-*
	.byte	$00
	.word	StopCode
	.byte	$53,$54,$4f,$d0
_end98:

; *** swap [ID:99] ***
	.byte	_end99-*
	.byte	$00
	.word	Swap
	.byte	$53,$57,$41,$d0
_end99:

; *** sys [ID:100] ***
	.byte	_end100-*
	.byte	$00
	.word	Call6502
	.byte	$53,$59,$d3
_end100:

; *** to.string [ID:101] ***
	.byte	_end101-*
	.byte	$00
	.word	IntToString
	.byte	$54,$4f,$2e,$53,$54,$52,$49,$4e,$c7
_end101:

; *** until [ID:102] ***
	.byte	_end102-*
	.byte	$21
	.word	UntilHandler
	.word	UntilEncoder
	.byte	$55,$4e,$54,$49,$cc
_end102:

; *** vlist [ID:103] ***
	.byte	_end103-*
	.byte	$00
	.word	VlistCode
	.byte	$56,$4c,$49,$53,$d4
_end103:

; *** xbreak [ID:104] ***
	.byte	_end104-*
	.byte	$40
	.word	BreakCmd
	.byte	$58,$42,$52,$45,$41,$cb
_end104:

; *** xdump [ID:105] ***
	.byte	_end105-*
	.byte	$00
	.word	ExitDump
	.byte	$58,$44,$55,$4d,$d0
_end105:

; *** xor [ID:106] ***
	.byte	_end106-*
	.byte	$00
	.word	Xor
	.byte	$58,$4f,$d2
_end106:

; *** save [ID:107] ***
	.byte	_end107-*
	.byte	$00
	.word	System_Save
	.byte	$53,$41,$56,$c5
_end107:

; *** load [ID:108] ***
	.byte	_end108-*
	.byte	$00
	.word	System_Load
	.byte	$4c,$4f,$41,$c4
_end108:

; *** $$index [ID:109] ***
	.byte	_end109-*
	.byte	$11
	.word	IndexHandler
	.word	IndexHandlerDecode
	.byte	$24,$24,$49,$4e,$44,$45,$d8
_end109:

	.byte	0

