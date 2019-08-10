all:
	g++ $(f).cpp -o $(f) -Wall -std=c++17

hack:
	./gen > in
	./B < in > o1
	./B3 < in > o2
	diff -w o1 o2
	make hack