; *****************************************************************************
; *****************************************************************************
;
;		Name :		files.asm
;		Purpose :	RPL-C Includes
;		Author :	Paul Robson (paul@robsons.org.uk)
;		Date : 		17th January 2020
;
; *****************************************************************************
; *****************************************************************************
;
;		This is the first thing after the JMP at the start. Keep it as
;		stable as possible.
;
		.include 	"code/core.src"			
		
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
		.include 	"words/system/decode.src"
		.include 	"words/system/edit.src"
		.include 	"words/system/list.src"
		.include 	"words/system/miscellany.src"
		.include 	"words/system/old.src"
		.include 	"words/system/saveload.src"
		.include 	"words/system/skipper.src"
		.include 	"words/system/toint.src"
		.include 	"words/system/tostr.src"
		.include 	"words/system/varhandlers.src"

		.include 	"words/encode/encode.src"
		.include 	"words/encode/comstr.src"
		.include 	"words/encode/encdef.src"
		.include 	"words/encode/encutils.src"
		.include 	"words/encode/encsearch.src"
		.include 	"words/encode/encvar.src"
