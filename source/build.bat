@echo off
del /Q *.bin
del /Q generated\*
python scripts\scanner.py
64tass -q -c kernel.asm -o kernel.prg -L kernel.lst -l kernel.lbl
if errorlevel 1 goto exit
python scripts\dictaddr.py
..\..\x16-emulator\x16emu -scale 2 -prg kernel.prg -run -dump R -debug
python scripts\show.py
:exit