#
#		Testing for encode/decode.
#
#		Has to be run once before repeat testing because of
#		program being generated from previous binary
#
rm dump*.bin kernel.prg generated/*
set -e
python scripts/scanner.py
python scripts/timestamp.py >generated/timestamp.inc
python scripts/encdectest.py
64tass -q -c -D encode=1 kernel.asm -o kernel_nocode.prg -L kernel.lst -l kernel.lbl
cat kernel_nocode.prg generated/rplcode.bin >kernel.prg
time ../../x16-r36/x16emu -scale 2 -prg kernel.prg -run -dump R -debug 
python scripts/check.py
