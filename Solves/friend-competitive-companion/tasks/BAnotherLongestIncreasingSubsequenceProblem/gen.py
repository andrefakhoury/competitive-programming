from random import *

N = 100000
print(N)

X = int(1e9)

for i in range(N):
	print(randint(-X, X), randint(-X, X))