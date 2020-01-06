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

FlatBuild = $1000 							; code starts here.
FreeMemory = $3000 							; compiled code etc/ here

		.include 	"data.asm"

		* = FlatBuild

		ldx 		#$FF 					; reset the stack
		txs
		ldx			#BootCode & $FF 		; boot address
		ldy 		#BootCode >>8
		jsr 		InitialiseCoreCode 		; initialise the NEXT routine at $00
		jmp 		Next

		.include 	"core.src"			
		.include 	"words/arithmetic/binary.src"
		.include 	"words/arithmetic/compare.src"
		.include 	"words/arithmetic/divide.src"
		.include 	"words/arithmetic/multiply.src"
		.include 	"words/arithmetic/unary.src"
		.include 	"words/system/callhandler.src"
		.include 	"words/system/debug.src"
		.include 	"words/system/miscellany.src"
		.include 	"words/system/number.src"
		.include 	"words/system/skipper.src"
		.include 	"words/system/varhandlers.src"
		.include 	"words/data/literals.src"
		.include 	"words/data/stack.src"
		.include 	"words/data/memory.src"

Dictionary:
		.include 	"generated/dictionary.inc"
				
BootCode:
		.byte 		Line20-BootCode
		.word 		10
		.word 		Literal2Byte
		.word 		$ABCD

		.word 		LiteralString
		.text 		4,"AB",0

		.word 		Literal2Byte
		.word 		$3345
		.word 		Literal2Byte
		.word 		$2234
		.word 		Literal2Byte
		.word 		$1123
		.word 		NextLine

Line20:	.byte 		EndOfProgram-Line20
		.word 		20
		.word 		Rot
		.word 		Literal2Byte
		.word 		$CDEF
		.word 		ExitDump
		.word 		NextLine
EndOfProgram:
		.byte 		0

