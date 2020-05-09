import random

print(1)

N = 4
print(N, N)
for i in range(N):
	for j in range(N):
		print(random.randint(0, 1), end = ' ')
	print()