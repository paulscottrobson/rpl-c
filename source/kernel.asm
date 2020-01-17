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
		jmp 	ColdStart
		.include "files.asm" 				; minimises address change hopefully.

ColdStart:		
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
