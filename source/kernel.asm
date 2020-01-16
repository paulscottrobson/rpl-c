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

		.include 	"code/data.asm"

		* = RplBuild

		ldx 	#$FF 						; reset the stack
		txs
		jsr 	ExternInitialise
		lda 	#BootMsg & $FF
		ldy 	#BootMsg >> 8
		jsr 	EXPrintString
WarmStartBlankStack:				
		resetStack 							; set up S to point to empty number stack

		.if encode != 0
		jmp 	EncodeTest
		.endif

WarmStart:	
		lda 	#COL_Yellow
		jsr 	ExternColour
		jsr 	ExternInput
		lda 	#COL_Cyan
		jsr 	ExternColour
		ldx 	#encodeBuffer & $FF 		; run what is in the encode buffer.
		ldy 	#encodeBuffer >> 8
		jsr 	InitialiseCoreCode 			; initialise the NEXT routine at $00 so error line# works
		lda 	#textBuffer & $FF
		ldy 	#textBuffer >> 8
		jsr 	EncodeProgram
		lda 	encodeBuffer+1 				; has a line number been entered ?
		ora 	encodeBuffer+2 				
		bne 	LineEditor 					; if so, do the line editing code.
		;
		;		Execute encoded line.
		;
		resetRSP 							; clear the return stack.
		doNext

LineEditor:
		jsr 	EditProgram
		bra 	WarmStartBlankStack			

		.include 	"code/core.src"			
		
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
		.include 	"words/encode/encvar.src"

		.include 	"words/structures/fornext.src"
		.include 	"words/structures/ifelseendif.src"
		.include 	"words/structures/repeatuntil.src"

		.include 	"words/system/branch.src"
		.include 	"words/system/callhandler.src"
		.include 	"words/system/clrnew.src"
		.include 	"words/system/debug.src"
		.include 	"words/system/decode.src"
		.include 	"words/system/edit.src"
		.include 	"words/system/list.src"
		.include 	"words/system/miscellany.src"
		.include 	"words/system/old.src"
		.include 	"words/system/saveload.src"
		.include 	"words/system/skipper.src"
		.include 	"words/system/toint.src"
		.include 	"words/system/tostr.src"
		.include 	"words/system/varhandlers.src"

BootMsg:
		.text 	"*** RPL/C INTERPRETER ***",13,13
		.text	"WRITTEN BY PAUL ROBSON 2020",13,13
		.text 	"BUILD: "
		.include 	"generated/timestamp.inc"
		.byte 	13,13,0

		.include 	"code/error.asm"
		.include 	"code/extern.asm"

		
Dictionary:
		.include 	"generated/dictionary.inc"
	
		.include 	"code/enctest.asm"

		* = $3FFF
		.byte 	$FF
ProgramMemory:
