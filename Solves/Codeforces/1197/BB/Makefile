all:
	./gen > in
	./B1 < in > o1
	./B2 < in > o2
	diff -w o1 o2
	make
