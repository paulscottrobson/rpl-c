#
#		Delete auto-generated code and dumps
#
rm *.bin generated/* kernel.prg
set -e
#
# 	Scan files and build dictionary of known words
#
python scripts/scanner.py
#
#		Build the kernel, with no code.
#
64tass -q -c kernel.asm -o kernel_nocode.prg -L kernel.lst -l kernel.lbl
#
#		Convert rpl/test.rpl to RPL tokenised/compiled code
#
python scripts/rplconv.py
#
#		Batten it onto the end of the executable
#
cat kernel_nocode.prg generated/rplcode.bin >kernel.prg
#
#		Run it on the emulator
#
../../x16-emulator/x16emu -scale 2 -prg kernel.prg -run -dump R -debug
#
#		Dump the stack.
#
python scripts/show.py
