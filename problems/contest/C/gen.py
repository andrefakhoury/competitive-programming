from random import randint

T = int(100)
N = int(1500)
X = int(1e5)
Q = int(5e4)

print(T)

for ts in range(T):
	print(N)

	for i in range(N):
		print(randint(-X, X), randint(-X, X), randint(-X, X))

	print(Q)
	for i in range(Q):
		print(randint(-X, X))
