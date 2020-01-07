@echo off
rem
rem		Delete auto-generated code and dumps
rem
del /Q *.bin
del /Q generated\*
rem
rem 	Scan files and build dictionary of known words
rem
python scripts\scanner.py
rem
rem		Build the kernel, with no code.
rem
64tass -q -c kernel.asm -o kernel_nocode.prg -L kernel.lst -l kernel.lbl
if errorlevel 1 goto exit
rem
rem		Convert rpl/test.rpl to RPL tokenised/compiled code
rem
python scripts\rplconv.py
if errorlevel 1 goto exit
rem
rem		Batten it onto the end of the executable
rem
copy /B kernel_nocode.prg +generated\rplcode.bin kernel.prg
rem
rem		Run it on the emulator
rem
..\..\x16-emulator\x16emu -scale 2 -prg kernel.prg -run -dump R -debug
rem
rem		Dump the stack.
rem
python scripts\show.py
:exit