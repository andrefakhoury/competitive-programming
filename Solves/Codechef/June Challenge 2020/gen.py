import random

T = 10
print(T)
for it in range(T):
	for j in range(2):
		for i in range(3):
			print(random.randint(-10, 10), end=' ')
		print()