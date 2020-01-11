; *****************************************************************************
; *****************************************************************************
;
;		Name :		kernel.asm
;		Purpose :	RPL-C Kernel.
;		Author :	Paul Robson (paul@robsons.org.uk)
;		Date : 		6th January 2020
;
; *****************************************************************************
; *****************************************************************************

RplBuild = $1000 							; code starts here.

		.include 	"data.asm"

		* = RplBuild

		ldx 	#$FF 						; reset the stack
		txs
		jsr 	ExternInitialise
		lda 	#BootMsg & $FF
		ldy 	#BootMsg >> 8
		jsr 	EXPrintString
WarmStartBlankStack:				
		resetStack 							; set up S to point to empty number stack

		.if encode == 1
		jmp 	EncodeTest
		.endif

WarmStart:	
		lda 	#COL_Yellow
		jsr 	ExternColour
		jsr 	ExternInput
		lda 	#COL_Cyan
		jsr 	ExternColour
		jmp 	RunProgram	

ErrorHandler:
		.byte 	$FF
		ldx 	#$5E

BootMsg:
		.text 	"*** RPL/C INTERPRETER ***",13,13
		.text	"WRITTEN BY PAUL ROBSON 2020",13,13
		.text 	"BUILD: "
		.include 	"generated/timestamp.inc"
		.byte 	13,13,0

		.include 	"core.src"			
		.include 	"extern.asm"

		.include 	"words/arithmetic/binary.src"
		.include 	"words/arithmetic/compare.src"
		.include 	"words/arithmetic/divide.src"
		.include 	"words/arithmetic/multiply.src"
		.include 	"words/arithmetic/unary.src"

		.include 	"words/data/literals.src"
		.include 	"words/data/stack.src"
		.include 	"words/data/memory.src"

		.include 	"words/encode/encode.src"
		.include 	"words/encode/comstr.src"
		.include 	"words/encode/encdef.src"
		.include 	"words/encode/encutils.src"
		.include 	"words/encode/encsearch.src"
		.include 	"words/structures/fornext.src"
		.include 	"words/structures/ifelseendif.src"
		.include 	"words/structures/repeatuntil.src"

		.include 	"words/system/branch.src"
		.include 	"words/system/callhandler.src"
		.include 	"words/system/clrnew.src"
		.include 	"words/system/debug.src"
		.include 	"words/system/decode.src"
		.include 	"words/system/list.src"
		.include 	"words/system/miscellany.src"
		.include 	"words/system/toint.src"
		.include 	"words/system/skipper.src"
		.include 	"words/system/tostr.src"
		.include 	"words/system/varhandlers.src"

		
Dictionary:
		.include 	"generated/dictionary.inc"
		
		.if encode == 1
EncodeTest:
		lda 	#(EncodeTestLine & $FF)
		ldy 	#(EncodeTestLine >> 8)
		jsr 	EncodeProgram
		set16 	bufPtr,textBuffer
		ldy 	#encodeBuffer>>8
		lda 	#encodeBuffer & $FF
		sec
		jsr 	DecodeLineIntoBufPtr
		jmp 	$FFFF
EncodeTestLine:
		.include 	"generated/edtext.inc"
		.endif

		* = $3FFF
		.byte 	$FF
ProgramMemory:
