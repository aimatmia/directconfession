GCC = gcc -g

all: main.c
	$(GCC) main.c -o dir

clean:
	rm *~

run: all
	./dir
