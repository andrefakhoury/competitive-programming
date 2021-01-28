from random import randint

N = 10000000000000

T = 100000

print(T)
for i in range(T):
	A = randint(10, N)
	B = randint(A, N)
	print(A, B)