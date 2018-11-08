@ set testPrg= ..\cmake-build-debug\Trojuhelniky1.exe
@ echo testovany program = %testPrg%

@ %testPrg% < 0000_in.txt > 0000_out_zz.txt
@ %testPrg% < 0001_in.txt > 0001_out_zz.txt
@ %testPrg% < 0002_in.txt > 0002_out_zz.txt
@ %testPrg% < 0003_in.txt > 0003_out_zz.txt
@ %testPrg% < 0003_in.txt > 0003_out_zz.txt
@ %testPrg% < 0004_in.txt > 0004_out_zz.txt
@ %testPrg% < 0005_in.txt > 0005_out_zz.txt
@ %testPrg% < 0006_in.txt > 0006_out_zz.txt
@ %testPrg% < 0007_in.txt > 0007_out_zz.txt

@ fc 0000_out_zz.txt 0000_out_win.txt
@ fc 0001_out_zz.txt 0001_out_win.txt
@ fc 0002_out_zz.txt 0002_out_win.txt
@ fc 0003_out_zz.txt 0003_out_win.txt
@ fc 0004_out_zz.txt 0004_out_win.txt
@ fc 0005_out_zz.txt 0005_out_win.txt
@ fc 0006_out_zz.txt 0006_out_win.txt
@ fc 0007_out_zz.txt 0007_out_win.txt
