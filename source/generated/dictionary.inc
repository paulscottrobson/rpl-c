; *** ! ***
	.byte	_end1-*
	.byte	$00
	.word	WordWrite
	.byte	$a1
_end1:

; *** $$literal ***
	.byte	_end2-*
	.byte	$40
	.word	Literal2Byte
	.byte	$24,$24,$4c,$49,$54,$45,$52,$41,$cc
_end2:

; *** * ***
	.byte	_end3-*
	.byte	$00
	.word	Multiply16x16
	.byte	$aa
_end3:

; *** + ***
	.byte	_end4-*
	.byte	$00
	.word	Add
	.byte	$ab
_end4:

; *** +! ***
	.byte	_end5-*
	.byte	$00
	.word	WordAdd
	.byte	$2b,$a1
_end5:

; *** - ***
	.byte	_end6-*
	.byte	$00
	.word	Subtract
	.byte	$ad
_end6:

; *** -1 ***
	.byte	_end7-*
	.byte	$00
	.word	ConstantMinus1
	.byte	$2d,$b1
_end7:

; *** / ***
	.byte	_end8-*
	.byte	$00
	.word	Divide16x16
	.byte	$af
_end8:

; *** 0 ***
	.byte	_end9-*
	.byte	$00
	.word	Constant0
	.byte	$b0
_end9:

; *** 0< ***
	.byte	_end10-*
	.byte	$00
	.word	CheckMinus
	.byte	$30,$bc
_end10:

; *** 0= ***
	.byte	_end11-*
	.byte	$00
	.word	CheckZero
	.byte	$30,$bd
_end11:

; *** 1 ***
	.byte	_end12-*
	.byte	$00
	.word	C1
	.byte	$b1
_end12:

; *** 1+ ***
	.byte	_end13-*
	.byte	$00
	.word	Unary1Plus
	.byte	$31,$ab
_end13:

; *** 1- ***
	.byte	_end14-*
	.byte	$00
	.word	Unary1Minus
	.byte	$31,$ad
_end14:

; *** 10 ***
	.byte	_end15-*
	.byte	$00
	.word	C10
	.byte	$31,$b0
_end15:

; *** 100 ***
	.byte	_end16-*
	.byte	$00
	.word	C100
	.byte	$31,$30,$b0
_end16:

; *** 1024 ***
	.byte	_end17-*
	.byte	$00
	.word	C1024
	.byte	$31,$30,$32,$b4
_end17:

; *** 127 ***
	.byte	_end18-*
	.byte	$00
	.word	C127
	.byte	$31,$32,$b7
_end18:

; *** 128 ***
	.byte	_end19-*
	.byte	$00
	.word	C128
	.byte	$31,$32,$b8
_end19:

; *** 15 ***
	.byte	_end20-*
	.byte	$00
	.word	C15
	.byte	$31,$b5
_end20:

; *** 16 ***
	.byte	_end21-*
	.byte	$00
	.word	C16
	.byte	$31,$b6
_end21:

; *** 16* ***
	.byte	_end22-*
	.byte	$00
	.word	Times16
	.byte	$31,$36,$aa
_end22:

; *** 2 ***
	.byte	_end23-*
	.byte	$00
	.word	C2
	.byte	$b2
_end23:

; *** 2* ***
	.byte	_end24-*
	.byte	$00
	.word	Times2
	.byte	$32,$aa
_end24:

; *** 2+ ***
	.byte	_end25-*
	.byte	$00
	.word	Unary2Plus
	.byte	$32,$ab
_end25:

; *** 2- ***
	.byte	_end26-*
	.byte	$00
	.word	Unary2Minus
	.byte	$32,$ad
_end26:

; *** 2/ ***
	.byte	_end27-*
	.byte	$00
	.word	Divide2
	.byte	$32,$af
_end27:

; *** 24 ***
	.byte	_end28-*
	.byte	$00
	.word	C24
	.byte	$32,$b4
_end28:

; *** 255 ***
	.byte	_end29-*
	.byte	$00
	.word	C255
	.byte	$32,$35,$b5
_end29:

; *** 256 ***
	.byte	_end30-*
	.byte	$00
	.word	C256
	.byte	$32,$35,$b6
_end30:

; *** 3 ***
	.byte	_end31-*
	.byte	$00
	.word	C3
	.byte	$b3
_end31:

; *** 32 ***
	.byte	_end32-*
	.byte	$00
	.word	C32
	.byte	$33,$b2
_end32:

; *** 32767 ***
	.byte	_end33-*
	.byte	$00
	.word	C32767
	.byte	$33,$32,$37,$36,$b7
_end33:

; *** 32768 ***
	.byte	_end34-*
	.byte	$00
	.word	C32768
	.byte	$33,$32,$37,$36,$b8
_end34:

; *** 4 ***
	.byte	_end35-*
	.byte	$00
	.word	C4
	.byte	$b4
_end35:

; *** 4* ***
	.byte	_end36-*
	.byte	$00
	.word	Times4
	.byte	$34,$aa
_end36:

; *** 40 ***
	.byte	_end37-*
	.byte	$00
	.word	C50
	.byte	$34,$b0
_end37:

; *** 4096 ***
	.byte	_end38-*
	.byte	$00
	.word	C4096
	.byte	$34,$30,$39,$b6
_end38:

; *** 48 ***
	.byte	_end39-*
	.byte	$00
	.word	C48
	.byte	$34,$b8
_end39:

; *** 5 ***
	.byte	_end40-*
	.byte	$00
	.word	C5
	.byte	$b5
_end40:

; *** 512 ***
	.byte	_end41-*
	.byte	$00
	.word	C512
	.byte	$35,$31,$b2
_end41:

; *** 63 ***
	.byte	_end42-*
	.byte	$00
	.word	C63
	.byte	$36,$b3
_end42:

; *** 64 ***
	.byte	_end43-*
	.byte	$00
	.word	C64
	.byte	$36,$b4
_end43:

; *** 8 ***
	.byte	_end44-*
	.byte	$00
	.word	C8
	.byte	$b8
_end44:

; *** < ***
	.byte	_end45-*
	.byte	$00
	.word	CheckLess
	.byte	$bc
_end45:

; *** = ***
	.byte	_end46-*
	.byte	$00
	.word	CheckEqual
	.byte	$bd
_end46:

; *** > ***
	.byte	_end47-*
	.byte	$00
	.word	CheckGreater
	.byte	$be
_end47:

; *** ?dup ***
	.byte	_end48-*
	.byte	$00
	.word	TestDup
	.byte	$3f,$44,$55,$d0
_end48:

; *** @ ***
	.byte	_end49-*
	.byte	$00
	.word	WordRead
	.byte	$c0
_end49:

; *** abs ***
	.byte	_end50-*
	.byte	$00
	.word	Absolute
	.byte	$41,$42,$d3
_end50:

; *** and ***
	.byte	_end51-*
	.byte	$00
	.word	And
	.byte	$41,$4e,$c4
_end51:

; *** bswap ***
	.byte	_end52-*
	.byte	$00
	.word	ByteSwap
	.byte	$42,$53,$57,$41,$d0
_end52:

; *** c! ***
	.byte	_end53-*
	.byte	$00
	.word	ByteWrite
	.byte	$43,$a1
_end53:

; *** c@ ***
	.byte	_end54-*
	.byte	$00
	.word	ByteRead
	.byte	$43,$c0
_end54:

; *** drop ***
	.byte	_end55-*
	.byte	$00
	.word	Drop
	.byte	$44,$52,$4f,$d0
_end55:

; *** dup ***
	.byte	_end56-*
	.byte	$00
	.word	Dup
	.byte	$44,$55,$d0
_end56:

; *** max ***
	.byte	_end57-*
	.byte	$00
	.word	Maximum
	.byte	$4d,$41,$d8
_end57:

; *** min ***
	.byte	_end58-*
	.byte	$00
	.word	Minimum
	.byte	$4d,$49,$ce
_end58:

; *** mod ***
	.byte	_end59-*
	.byte	$00
	.word	Modulus16x16
	.byte	$4d,$4f,$c4
_end59:

; *** negate ***
	.byte	_end60-*
	.byte	$00
	.word	Negate
	.byte	$4e,$45,$47,$41,$54,$c5
_end60:

; *** nip ***
	.byte	_end61-*
	.byte	$00
	.word	Nip
	.byte	$4e,$49,$d0
_end61:

; *** not ***
	.byte	_end62-*
	.byte	$00
	.word	OneComplement
	.byte	$4e,$4f,$d4
_end62:

; *** or ***
	.byte	_end63-*
	.byte	$00
	.word	LogOr
	.byte	$4f,$d2
_end63:

; *** over ***
	.byte	_end64-*
	.byte	$00
	.word	Over
	.byte	$4f,$56,$45,$d2
_end64:

; *** rot ***
	.byte	_end65-*
	.byte	$00
	.word	Rot
	.byte	$52,$4f,$d4
_end65:

; *** swap ***
	.byte	_end66-*
	.byte	$00
	.word	Swap
	.byte	$53,$57,$41,$d0
_end66:

; *** sys ***
	.byte	_end67-*
	.byte	$00
	.word	Call6502
	.byte	$53,$59,$d3
_end67:

; *** xbreak ***
	.byte	_end68-*
	.byte	$40
	.word	BreakCmd
	.byte	$58,$42,$52,$45,$41,$cb
_end68:

; *** xdump ***
	.byte	_end69-*
	.byte	$00
	.word	ExitDump
	.byte	$58,$44,$55,$4d,$d0
_end69:

; *** xor ***
	.byte	_end70-*
	.byte	$00
	.word	Xor
	.byte	$58,$4f,$d2
_end70:

	.byte	0

