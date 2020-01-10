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

		ldx 		#$FF 					; reset the stack
		txs
		
		resetStack		
		jsr 		ClearVariableSpace 		; clear variables etc.
		ldx			#ProgramMemory & $FF	; boot address
		ldy 		#ProgramMemory >>8
		jsr 		InitialiseCoreCode 		; initialise the NEXT routine at $00
		jmp 		Next

		.include 	"core.src"			

		.include 	"decode/list.src"

		.include 	"words/arithmetic/binary.src"
		.include 	"words/arithmetic/compare.src"
		.include 	"words/arithmetic/divide.src"
		.include 	"words/arithmetic/multiply.src"
		.include 	"words/arithmetic/unary.src"

		.include 	"words/data/literals.src"
		.include 	"words/data/stack.src"
		.include 	"words/data/memory.src"


		.include 	"words/structures/fornext.src"
		.include 	"words/structures/ifelseendif.src"
		.include 	"words/structures/repeatuntil.src"

		.include 	"words/system/branch.src"
		.include 	"words/system/callhandler.src"
		.include 	"words/system/clrnew.src"
		.include 	"words/system/debug.src"
		.include 	"words/system/miscellany.src"
		.include 	"words/system/toint.src"
		.include 	"words/system/skipper.src"
		.include 	"words/system/tostr.src"
		.include 	"words/system/varhandlers.src"

WarmStart:	
		.byte 	$FF
		ldx 	#$00
ErrorHandler:
		.byte 	$FF
		ldx 	#$5E

Dictionary:
		.include 	"generated/dictionary.inc"
				
		* = $3FFF
		.byte 	$FF
ProgramMemory:
