all:
	python3 gen.py > in
	./sol < in > o1
	./brute < in > o2
	diff -w o1 o2
	make