n = 200
print(n)

from random import randint

N = 10000
for i in range(n):
	x = randint(-N, N)
	y = randint(-N, N)
	r = randint(0, 5000)
	print(x, y, r)