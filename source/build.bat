@echo off
del *.bin
del generated\*
64tass -q -c kernel.asm -o kernel.prg -L kernel.lst -l kernel.lbl
if errorlevel 1 goto exit
..\..\x16-emulator\x16emu -scale 2 -prg kernel.prg -run -dump R -debug
python scripts\show.py
:exit