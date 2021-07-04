main.out: main.o MyWrapper.o MyClass.o
	g++ main.o MyWrapper.o MyClass.o -o main.out
	rm -f *.o
	clear
	./main.out

main.o: main.c
	gcc -c main.c -o main.o

MyWrapper.o: MyWrapper.cc
	g++ -c MyWrapper.cc -o MyWrapper.o

MyClass.o: MyClass.cc
	g++ -c MyClass.cc -o MyClass.o

clean:
	rm -f *.o *.out
	clear