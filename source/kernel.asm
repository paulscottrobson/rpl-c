; *****************************************************************************
; *****************************************************************************
;
;		Name :		kernel.asm
;		Purpose :	Flat6502 Kernel.
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

		.include 	"core.asm"				; Next/Exit/Enter/Gen Literals

		
BootCode:
		.word 		Literal2Byte
		.word 		$ABCD
		.word 		Literal2Byte
		.word 		$CDEF
		.word 		CrashDump

CrashDump:
		tsx 
		stx 		temp1
		jmp 		$FFFF		
			
