; *** ! ***
	.byte	_end1-*
	.byte	$00
	.word	WordWrite
	.byte	$a1
_end1:

; *** $$!handler ***
	.byte	_end2-*
	.byte	$42
	.word	VarWriteHandler
	.byte	$24,$24,$21,$48,$41,$4e,$44,$4c,$45,$d2
_end2:

; *** $$&handler ***
	.byte	_end3-*
	.byte	$42
	.word	VarAddressHandler
	.byte	$24,$24,$26,$48,$41,$4e,$44,$4c,$45,$d2
_end3:

; *** $$@handler ***
	.byte	_end4-*
	.byte	$42
	.word	VarReadHandler
	.byte	$24,$24,$40,$48,$41,$4e,$44,$4c,$45,$d2
_end4:

; *** $$call ***
	.byte	_end5-*
	.byte	$42
	.word	CallHandler
	.byte	$24,$24,$43,$41,$4c,$cc
_end5:

; *** $$comment ***
	.byte	_end6-*
	.byte	$43
	.word	SkipComment
	.byte	$24,$24,$43,$4f,$4d,$4d,$45,$4e,$d4
_end6:

; *** $$define ***
	.byte	_end7-*
	.byte	$43
	.word	DefineCode
	.byte	$24,$24,$44,$45,$46,$49,$4e,$c5
_end7:

; *** $$literal ***
	.byte	_end8-*
	.byte	$42
	.word	Literal2Byte
	.byte	$24,$24,$4c,$49,$54,$45,$52,$41,$cc
_end8:

; *** $$nextline ***
	.byte	_end9-*
	.byte	$80
	.word	NextLine
	.byte	$24,$24,$4e,$45,$58,$54,$4c,$49,$4e,$c5
_end9:

; *** $$string ***
	.byte	_end10-*
	.byte	$43
	.word	LiteralString
	.byte	$24,$24,$53,$54,$52,$49,$4e,$c7
_end10:

; *** * ***
	.byte	_end11-*
	.byte	$00
	.word	Multiply16x16
	.byte	$aa
_end11:

; *** + ***
	.byte	_end12-*
	.byte	$00
	.word	Add
	.byte	$ab
_end12:

; *** +! ***
	.byte	_end13-*
	.byte	$00
	.word	WordAdd
	.byte	$2b,$a1
_end13:

; *** - ***
	.byte	_end14-*
	.byte	$00
	.word	Subtract
	.byte	$ad
_end14:

; *** -1 ***
	.byte	_end15-*
	.byte	$00
	.word	ConstantMinus1
	.byte	$2d,$b1
_end15:

; *** / ***
	.byte	_end16-*
	.byte	$00
	.word	Divide16x16
	.byte	$af
_end16:

; *** 0 ***
	.byte	_end17-*
	.byte	$00
	.word	Constant0
	.byte	$b0
_end17:

; *** 0< ***
	.byte	_end18-*
	.byte	$00
	.word	CheckMinus
	.byte	$30,$bc
_end18:

; *** 0= ***
	.byte	_end19-*
	.byte	$00
	.word	CheckZero
	.byte	$30,$bd
_end19:

; *** 1 ***
	.byte	_end20-*
	.byte	$00
	.word	C1
	.byte	$b1
_end20:

; *** 1+ ***
	.byte	_end21-*
	.byte	$00
	.word	Unary1Plus
	.byte	$31,$ab
_end21:

; *** 1- ***
	.byte	_end22-*
	.byte	$00
	.word	Unary1Minus
	.byte	$31,$ad
_end22:

; *** 10 ***
	.byte	_end23-*
	.byte	$00
	.word	C10
	.byte	$31,$b0
_end23:

; *** 100 ***
	.byte	_end24-*
	.byte	$00
	.word	C100
	.byte	$31,$30,$b0
_end24:

; *** 1024 ***
	.byte	_end25-*
	.byte	$00
	.word	C1024
	.byte	$31,$30,$32,$b4
_end25:

; *** 127 ***
	.byte	_end26-*
	.byte	$00
	.word	C127
	.byte	$31,$32,$b7
_end26:

; *** 128 ***
	.byte	_end27-*
	.byte	$00
	.word	C128
	.byte	$31,$32,$b8
_end27:

; *** 15 ***
	.byte	_end28-*
	.byte	$00
	.word	C15
	.byte	$31,$b5
_end28:

; *** 16 ***
	.byte	_end29-*
	.byte	$00
	.word	C16
	.byte	$31,$b6
_end29:

; *** 16* ***
	.byte	_end30-*
	.byte	$00
	.word	Times16
	.byte	$31,$36,$aa
_end30:

; *** 16/ ***
	.byte	_end31-*
	.byte	$00
	.word	Divide16
	.byte	$31,$36,$af
_end31:

; *** 2 ***
	.byte	_end32-*
	.byte	$00
	.word	C2
	.byte	$b2
_end32:

; *** 2* ***
	.byte	_end33-*
	.byte	$00
	.word	Times2
	.byte	$32,$aa
_end33:

; *** 2+ ***
	.byte	_end34-*
	.byte	$00
	.word	Unary2Plus
	.byte	$32,$ab
_end34:

; *** 2- ***
	.byte	_end35-*
	.byte	$00
	.word	Unary2Minus
	.byte	$32,$ad
_end35:

; *** 2/ ***
	.byte	_end36-*
	.byte	$00
	.word	Divide2
	.byte	$32,$af
_end36:

; *** 24 ***
	.byte	_end37-*
	.byte	$00
	.word	C24
	.byte	$32,$b4
_end37:

; *** 255 ***
	.byte	_end38-*
	.byte	$00
	.word	C255
	.byte	$32,$35,$b5
_end38:

; *** 256 ***
	.byte	_end39-*
	.byte	$00
	.word	C256
	.byte	$32,$35,$b6
_end39:

; *** 256* ***
	.byte	_end40-*
	.byte	$00
	.word	Times256
	.byte	$32,$35,$36,$aa
_end40:

; *** 256/ ***
	.byte	_end41-*
	.byte	$00
	.word	Divide256
	.byte	$32,$35,$36,$af
_end41:

; *** 3 ***
	.byte	_end42-*
	.byte	$00
	.word	C3
	.byte	$b3
_end42:

; *** 32 ***
	.byte	_end43-*
	.byte	$00
	.word	C32
	.byte	$33,$b2
_end43:

; *** 32767 ***
	.byte	_end44-*
	.byte	$00
	.word	C32767
	.byte	$33,$32,$37,$36,$b7
_end44:

; *** 32768 ***
	.byte	_end45-*
	.byte	$00
	.word	C32768
	.byte	$33,$32,$37,$36,$b8
_end45:

; *** 4 ***
	.byte	_end46-*
	.byte	$00
	.word	C4
	.byte	$b4
_end46:

; *** 4* ***
	.byte	_end47-*
	.byte	$00
	.word	Times4
	.byte	$34,$aa
_end47:

; *** 4/ ***
	.byte	_end48-*
	.byte	$00
	.word	Divide4
	.byte	$34,$af
_end48:

; *** 4096 ***
	.byte	_end49-*
	.byte	$00
	.word	C4096
	.byte	$34,$30,$39,$b6
_end49:

; *** 5 ***
	.byte	_end50-*
	.byte	$00
	.word	C5
	.byte	$b5
_end50:

; *** 512 ***
	.byte	_end51-*
	.byte	$00
	.word	C512
	.byte	$35,$31,$b2
_end51:

; *** 63 ***
	.byte	_end52-*
	.byte	$00
	.word	C63
	.byte	$36,$b3
_end52:

; *** 64 ***
	.byte	_end53-*
	.byte	$00
	.word	C64
	.byte	$36,$b4
_end53:

; *** 8 ***
	.byte	_end54-*
	.byte	$00
	.word	C8
	.byte	$b8
_end54:

; *** 8* ***
	.byte	_end55-*
	.byte	$00
	.word	Times8
	.byte	$38,$aa
_end55:

; *** 8/ ***
	.byte	_end56-*
	.byte	$00
	.word	Divide8
	.byte	$38,$af
_end56:

; *** ; ***
	.byte	_end57-*
	.byte	$40
	.word	ReturnHandler
	.byte	$bb
_end57:

; *** < ***
	.byte	_end58-*
	.byte	$00
	.word	CheckLess
	.byte	$bc
_end58:

; *** <= ***
	.byte	_end59-*
	.byte	$00
	.word	CheckLessEq
	.byte	$3c,$bd
_end59:

; *** <> ***
	.byte	_end60-*
	.byte	$00
	.word	CheckNotEqual
	.byte	$3c,$be
_end60:

; *** = ***
	.byte	_end61-*
	.byte	$00
	.word	CheckEqual
	.byte	$bd
_end61:

; *** > ***
	.byte	_end62-*
	.byte	$00
	.word	CheckGreater
	.byte	$be
_end62:

; *** >= ***
	.byte	_end63-*
	.byte	$00
	.word	CheckGreaterEq
	.byte	$3e,$bd
_end63:

; *** ?dup ***
	.byte	_end64-*
	.byte	$00
	.word	TestDup
	.byte	$3f,$44,$55,$d0
_end64:

; *** @ ***
	.byte	_end65-*
	.byte	$00
	.word	WordRead
	.byte	$c0
_end65:

; *** abs ***
	.byte	_end66-*
	.byte	$00
	.word	Absolute
	.byte	$41,$42,$d3
_end66:

; *** alloc ***
	.byte	_end67-*
	.byte	$00
	.word	AllocateMemory
	.byte	$41,$4c,$4c,$4f,$c3
_end67:

; *** and ***
	.byte	_end68-*
	.byte	$00
	.word	And
	.byte	$41,$4e,$c4
_end68:

; *** assert ***
	.byte	_end69-*
	.byte	$00
	.word	AssertCode
	.byte	$41,$53,$53,$45,$52,$d4
_end69:

; *** bswap ***
	.byte	_end70-*
	.byte	$00
	.word	ByteSwap
	.byte	$42,$53,$57,$41,$d0
_end70:

; *** c! ***
	.byte	_end71-*
	.byte	$00
	.word	ByteWrite
	.byte	$43,$a1
_end71:

; *** c@ ***
	.byte	_end72-*
	.byte	$00
	.word	ByteRead
	.byte	$43,$c0
_end72:

; *** clr ***
	.byte	_end73-*
	.byte	$00
	.word	ClrHandler
	.byte	$43,$4c,$d2
_end73:

; *** drop ***
	.byte	_end74-*
	.byte	$00
	.word	Drop
	.byte	$44,$52,$4f,$d0
_end74:

; *** dup ***
	.byte	_end75-*
	.byte	$00
	.word	Dup
	.byte	$44,$55,$d0
_end75:

; *** else ***
	.byte	_end76-*
	.byte	$01
	.word	ElseHandler
	.byte	$45,$4c,$53,$c5
_end76:

; *** end ***
	.byte	_end77-*
	.byte	$00
	.word	EndProgram
	.byte	$45,$4e,$c4
_end77:

; *** endif ***
	.byte	_end78-*
	.byte	$00
	.word	EndIfHandler
	.byte	$45,$4e,$44,$49,$c6
_end78:

; *** for ***
	.byte	_end79-*
	.byte	$00
	.word	ForHandler
	.byte	$46,$4f,$d2
_end79:

; *** if ***
	.byte	_end80-*
	.byte	$01
	.word	IfHandler
	.byte	$49,$c6
_end80:

; *** index ***
	.byte	_end81-*
	.byte	$00
	.word	GetIndex
	.byte	$49,$4e,$44,$45,$d8
_end81:

; *** max ***
	.byte	_end82-*
	.byte	$00
	.word	Maximum
	.byte	$4d,$41,$d8
_end82:

; *** min ***
	.byte	_end83-*
	.byte	$00
	.word	Minimum
	.byte	$4d,$49,$ce
_end83:

; *** mod ***
	.byte	_end84-*
	.byte	$00
	.word	Modulus16x16
	.byte	$4d,$4f,$c4
_end84:

; *** negate ***
	.byte	_end85-*
	.byte	$00
	.word	Negate
	.byte	$4e,$45,$47,$41,$54,$c5
_end85:

; *** new ***
	.byte	_end86-*
	.byte	$00
	.word	NewHandler
	.byte	$4e,$45,$d7
_end86:

; *** next ***
	.byte	_end87-*
	.byte	$01
	.word	NextHandler
	.byte	$4e,$45,$58,$d4
_end87:

; *** nip ***
	.byte	_end88-*
	.byte	$00
	.word	Nip
	.byte	$4e,$49,$d0
_end88:

; *** not ***
	.byte	_end89-*
	.byte	$00
	.word	OneComplement
	.byte	$4e,$4f,$d4
_end89:

; *** or ***
	.byte	_end90-*
	.byte	$00
	.word	LogOr
	.byte	$4f,$d2
_end90:

; *** over ***
	.byte	_end91-*
	.byte	$00
	.word	Over
	.byte	$4f,$56,$45,$d2
_end91:

; *** repeat ***
	.byte	_end92-*
	.byte	$00
	.word	RepeatHandler
	.byte	$52,$45,$50,$45,$41,$d4
_end92:

; *** rnd ***
	.byte	_end93-*
	.byte	$00
	.word	RandomNumber
	.byte	$52,$4e,$c4
_end93:

; *** rot ***
	.byte	_end94-*
	.byte	$00
	.word	Rot
	.byte	$52,$4f,$d4
_end94:

; *** sgn ***
	.byte	_end95-*
	.byte	$00
	.word	SignTOS
	.byte	$53,$47,$ce
_end95:

; *** stop ***
	.byte	_end96-*
	.byte	$00
	.word	StopCode
	.byte	$53,$54,$4f,$d0
_end96:

; *** swap ***
	.byte	_end97-*
	.byte	$00
	.word	Swap
	.byte	$53,$57,$41,$d0
_end97:

; *** sys ***
	.byte	_end98-*
	.byte	$00
	.word	Call6502
	.byte	$53,$59,$d3
_end98:

; *** to.integer ***
	.byte	_end99-*
	.byte	$00
	.word	NumToInt
	.byte	$54,$4f,$2e,$49,$4e,$54,$45,$47,$45,$d2
_end99:

; *** to.string ***
	.byte	_end100-*
	.byte	$00
	.word	IntToString
	.byte	$54,$4f,$2e,$53,$54,$52,$49,$4e,$c7
_end100:

; *** until ***
	.byte	_end101-*
	.byte	$01
	.word	UntilHandler
	.byte	$55,$4e,$54,$49,$cc
_end101:

; *** xbreak ***
	.byte	_end102-*
	.byte	$40
	.word	BreakCmd
	.byte	$58,$42,$52,$45,$41,$cb
_end102:

; *** xdump ***
	.byte	_end103-*
	.byte	$00
	.word	ExitDump
	.byte	$58,$44,$55,$4d,$d0
_end103:

; *** xor ***
	.byte	_end104-*
	.byte	$00
	.word	Xor
	.byte	$58,$4f,$d2
_end104:

	.byte	0

