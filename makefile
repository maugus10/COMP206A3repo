assignment : main2.o list2.o
	gcc -o assignment main2.o list2.o

main2.o : main2.c list2.c list2.h
	gcc -c main2.c

list2.o : list2.c list2.h
	gcc -c list2.c

clean : 
	rm -f assignment main2.o list2.o
