PYINCLUDE=/home/yudha/miniconda3/include/python3.8
PYLIB=/home/yudha/miniconda3/lib

all:
	gcc -c main.c -I${PYINCLUDE} -o main.o
	gcc main.o -L${PYLIB} -lpython3.8 -o main.out
	./main.out

clean:
	rm -f ./main.o ./main.out