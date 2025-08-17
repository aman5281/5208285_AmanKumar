object: main.o functions.o
	gcc -o object main.o functions.o

main.o: main.c funprototype.h
	gcc -c main.c

functions.o: functions.c funprototype.h
	gcc -c functions.c

run: object
	./object

clean:
	rm -f *.o object