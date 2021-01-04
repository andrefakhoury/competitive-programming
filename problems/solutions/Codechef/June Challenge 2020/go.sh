for (( c=1; c<=100000; c++ )); do
	./gen > in
	./TTUPLE < in > o2
	diff -w o2 o1
done