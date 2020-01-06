; *****************************************************************************
; *****************************************************************************
;
;		Name :		data.asm
;		Purpose :	Data allocation, Basic Macros
;		Author :	Paul Robson (paul@robsons.org.uk)
;		Date : 		6th January 2020
;
; *****************************************************************************
; *****************************************************************************

		* = $0

; *****************************************************************************
;
;								Zero Page Variables
;
; *****************************************************************************

Next: 										; NEXT code (INX INX JSR ($xxxx,X) goes here)
		.fill 	6

IP = Next+3 								; the IP which points to the current instruction

tos:
		.word 	?
temp1:										; general usage zero page
		.word 	?	
temp2:	
		.word 	?
temp3:	
		.word 	?
temp4:
		.word 	?
		
; *****************************************************************************
;
;							Other memory allocation
;
; *****************************************************************************

SignCount:		
		.byte 	?

stack2Low = $102
stack2High = $101
stack3Low = $104
stack3High = $103

; *****************************************************************************
;
;										Macros
;
; *****************************************************************************

rerror	.macro
		.byte 	$FF
_w1:	bra 	_w1
		.text 	\1,0
		.endm

set16 	.macro
		lda 	#(\2) & $FF
		sta 	0+(\1)
		lda 	#(\2) >> 8
		sta 	1+(\1)
		.endm

pushTOS .macro
		lda 	TOS
		pha
		lda 	TOS+1
		pha
		.endm
		
popTOS 	.macro
		pla
		sta 	TOS+1
		pla 	 
		sta 	TOS
		.endm			