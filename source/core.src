; *****************************************************************************
; *****************************************************************************
;
;		Name :		core.asm
;		Purpose :	Core Routines - Next, Enter, Exit, Literals
;		Author :	Paul Robson (paul@robsons.org.uk)
;		Date : 		6th January 2020
;
; *****************************************************************************
; *****************************************************************************

; *****************************************************************************
;
;		This sets up the "Next" code which uses self modifying code at $00
;						YX contains the first word to run.
;
; *****************************************************************************

InitialiseCoreCode:
		lda 	#$E8 					; Copy INX INX 			4 cycles when run
		sta 	Next
		sta 	Next+1
		lda 	#$7C 					; Copy JMP ($aaaa,x) 	6 cycles when run
		sta 	Next+2 
		stx 	Next+3 					; set the indirect address (IP)
		sty 	Next+4
		ldx 	#-2 					; set up to run from provided word.
		rts

; *****************************************************************************
;
;				Word that loads a 2 byte literal onto the stack.
;
; *****************************************************************************

Literal2Byte:	;; $$literal noexec
		pushTOS							; push the old TOS on the stack
		inx  							; point X to the word 
		inx 
		txa 							; copy into Y
		tay

		lda 	(IP),y 					; read it. the LSB
		sta 	TOS
		iny 							; read and push the MSB
		lda 	(IP),y
		sta 	TOS+1
		jmp 	Next
