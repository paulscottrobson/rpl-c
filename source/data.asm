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
		.fill 	5

IP = Next+3 								; the IP which points to the current instruction

rsp:										; return stack pointer.
		.byte 	?

tos:										; top of stack register
		.word 	?

nextFreeMem:								; next free variable/data memory.
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

RandomSeed:
		.byte 	?
		
stack2Low = $102							; access other stack members following tsx
stack2High = $101							; (which requires saving X, not on the stack !)
stack3Low = $104
stack3High = $103

azVariables = $600 							; 26 x 2 variables occupying 52 bytes * PAGE BOUNDARY *

hashTableSize = 16 							; hash tables for variables.
hashTable = $640 							; hash tables start here * ALL ON ONE PAGE *

returnStack = $700							; return stack (1 page)
returnStackLow = returnStack
returnStackHigh = returnStack+$40
returnStackX = returnStack+$80

; *****************************************************************************
;
;										Macros
;
; *****************************************************************************

rerror	.macro
		jsr 	ErrorHandler
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

advance	.macro
		clc
		lda 	\1
		adc 	(\1)
		sta 	\1
		bcc 	_NoCarryAdv
		inc 	\1+1
_NoCarryAdv:
		.endm				