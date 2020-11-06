from random import *

N = int(1e9)

n = randint(1, N)
m = randint(1, 100000)
a = randint(1, N)
d = randint(1, N*N)

print(n, m, a, d)
for i in range(m):
	print(randint(1, N*N), end=' ')