main.out: ./lib/libmyclass.a
	gcc main.cpp -L./lib -lmyclass -lstdc++ -o main.out && ./main.out

./lib/libmyclass.a: myclass.cpp
	mkdir -p ./lib
	gcc -c myclass.cpp --std=c++17 -o ./lib/myclass.o
	ar crv ./lib/libmyclass.a ./lib/myclass.o
	rm -f ./lib/myclass.o

clean:
	rm -f *.out ./lib/*.a