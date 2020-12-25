all:
	python3 gen.py > in
	./brute < in > o1
	./sol < in > o2
	diff -w o1 o2
	make