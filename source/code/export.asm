; *****************************************************************************
; *****************************************************************************
;
;		Name :		export.asm
;		Purpose :	Export test code
;		Author :	Paul Robson (paul@robsons.org.uk)
;		Date : 		14th January 2020
;
; *****************************************************************************
; *****************************************************************************
;
;		Encode testing. Encode = 1 means the edbuild.bat script is running which 
;		automatically tests encoding. Encode = 2 is for development ; the routine
;		is called, but uses the text in the source not the generated one.
;	
		.if encode != 0
EncodeTest:
		lda 	#(EncodeTestLine & $FF)
		ldy 	#(EncodeTestLine >> 8)
		jsr 	EncodeProgram
		set16 	bufPtr,textBuffer
		ldy 	#encodeBuffer>>8
		lda 	#encodeBuffer & $FF
		sec
		jsr 	DecodeLineIntoBufPtr
		.if encode == 2
		.byte 	$FF
		.endif
		jmp 	$FFFF
EncodeTestLine:
		.if encode == 1
		.include 	"generated/edtext.inc"
EncodeTestLineOriginal:
		.include 	"generated/edtext.inc"
		.else
		.text 	"518 :TEST.42  ",0
		.endif
		.endif
