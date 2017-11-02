all: directions.c
	gcc -o dir directions.c

clean:
	rm *o
	rm *~

run: all
	./dir
