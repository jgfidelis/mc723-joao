primo: primoMain.o calcPrimo.o
	gcc -o primo primoMain.o calcPrimo.o -O1

main.o: primoMain.c calcPrimo.h
	gcc -c primoMain.c -O1

calcPrimo.o: calcPrimo.c calcPrimo.h
	gcc -c calcPrimo.c -O1
