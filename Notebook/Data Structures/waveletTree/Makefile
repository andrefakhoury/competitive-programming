all:
	./gen > in
	./A < in > oA
	./wavelet < in > oW
	diff -w oA oW
	make

cmp:
	g++ $(f).cpp -o $(f) -Wall -O3