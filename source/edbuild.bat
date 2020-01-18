@echo off
rem
rem					Testing for encode / decode.
rem
rem		Has to be run once before repeat testing because of
rem		program being generated from previous binary
rem
del /Q dump*.bin 
del /Q kernel.prg 
del /Q generated\*

python scripts\scanner.py
python scripts\timestamp.py >generated\timestamp.inc
python scripts\encdectest.py
64tass -q -c -D encode=1 kernel.asm -o kernel_nocode.prg -L kernel.lst -l kernel.lbl
if errorlevel 1 goto exit
copy /B kernel_nocode.prg +generated\rplcode.bin kernel.prg
..\..\x16-r36\x16emu -scale 2 -prg kernel.prg -run -dump R -debug
python scripts\check.py
