from random import randint

n = int(1e5)
m = int(5e3)
print(n, m)

for i in range(n):
	print(randint(int(-1e9), int(1e9)), end=' ')
print()

for i in range(n):
	# l = randint(1, n)
	# r = randint(l, n)
	# k = randint(1, r - l + 1)
	l, r, k = 1, n, n
	print(l, r, k)