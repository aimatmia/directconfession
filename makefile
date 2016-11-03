GCC = gcc -g

all: direct.c
	$(GCC) direct.c -o dir

clean:
	rm *~

run: all
	./dir
