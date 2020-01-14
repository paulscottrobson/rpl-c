; *****************************************************************************
; *****************************************************************************
;
;		Name :		error.asm
;		Purpose :	Error Reporting
;		Author :	Paul Robson (paul@robsons.org.uk)
;		Date : 		14th January 2020
;
; *****************************************************************************
; *****************************************************************************

; *****************************************************************************
;
;			Error handler, entered via JSR, ASCIIZ message follows
;
; *****************************************************************************

ErrorHandler:
		pla 								; get message address
		ply
		inc 	a
		bne 	_EHNoCarry
		iny
_EHNoCarry:
		jsr 	EXPrintString
		ldy 	#1 							; check if there is a line #
		lda 	(IP),y
		iny
		ora 	(IP),y
		beq 	_EHNoLine
		lda 	#_EHMsg2 & $FF 				; print " at "
		ldy 	#_EHMsg2 >> 8
		jsr 	EXPrintString
		ldy 	#2 							; print line number
		lda 	(IP),y
		pha
		dey		
		lda 	(IP),y
		ply
		clc
		jsr 	PrintYA
_EHNoLine:
		lda 	#13
		jsr 	ExternPrint
		jmp 	WarmStartBlankStack			; S is indeterminate		

_EHMsg2:.text 	" AT ",0