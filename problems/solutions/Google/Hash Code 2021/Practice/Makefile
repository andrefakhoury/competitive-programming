all:
	g++ -static -Wall -O2 -std=c++17 $f.cpp -o $f

slow:
	g++ $(f).cpp -o $(f) -Wall -std=c++17 -DLOCAL_PC -fsanitize=address,undefined -ggdb3

run:
	./$f < cases/$(case).in 1> output/$(case)_$(shell ls output | wc -l 2> /dev/null).out

run_all:
	make run f=$f case=a
	make run f=$f case=b
	make run f=$f case=c
	make run f=$f case=d
	make run f=$f case=e