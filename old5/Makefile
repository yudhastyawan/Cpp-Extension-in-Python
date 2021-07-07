./exec/main.out: ./lib/myclass.o ./lib/mycalc.o ./lib/cwrapper.o ./lib/main.o
	g++ -I ./include ./lib/main.o ./lib/myclass.o ./lib/mycalc.o ./lib/cwrapper.o -o ./exec/main.out
	./exec/main.out

./lib/main.o: ./src/main.c
	gcc -c -I ./include ./src/main.c -o ./lib/main.o

./lib/cwrapper.o: ./src/cwrapper.cpp
	g++ -c -I ./include ./src/cwrapper.cpp -o ./lib/cwrapper.o

./lib/mycalc.o: ./src/mycalc.cpp
	g++ -c -I ./include ./src/mycalc.cpp -o ./lib/mycalc.o

./lib/myclass.o: ./src/myclass.cpp
	g++ -c -I ./include ./src/myclass.cpp -o ./lib/myclass.o

clean:
	rm -rf ./exec/*.out
	rm -rf ./lib/*.o