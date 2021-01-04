import random

N = 100
n = 350
m = 345
print(n, m, 5)
for i in range(n):
	for j in range(m):
		print(random.randint(-N, N), end=' ')
	print()
