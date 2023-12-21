all:
	gcc -ggdb -Wall --pedantic src/*.c -o bin/gauss

test: all
	bin/gauss dane/A dane/b   || true 
	bin/gauss dane/1 dane/1.1 || true
	bin/gauss dane/2 dane/2.1 || true 
	bin/gauss dane/3 dane/3.1 || true
	bin/gauss dane/4 dane/4.1 || true
