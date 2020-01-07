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

tos:										; top of stack register
		.word 	?

temp1:										; general usage zero page
		.word 	?	
temp2:	
		.word 	?
temp3:	
		.word 	?
temp4:
		.word 	?
		
freeMemory:									; start of free memory
		.word 	?

; *****************************************************************************
;
;							Other memory allocation
;
; *****************************************************************************

SignCount:		
		.byte 	?

stack2Low = $102							; access other stack members following tsx
stack2High = $101							; (which requires saving X, not on the stack !)
stack3Low = $104
stack3High = $103

azVariables = $600 							; 26 x 2 variables occupying 52 bytes.
hashTableSize = 16 							; hash tables for variables.
hashTables = $640 							; hash tables start here.

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