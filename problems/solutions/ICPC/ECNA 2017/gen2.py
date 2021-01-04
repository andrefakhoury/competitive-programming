from random import randint

def f(a, b, c):
	if a == 0 or b % a != 0:
		return 0
	return b // a + c * 24

a = -100
b = 1
c = 1

while(f(a, b, c) <= 0 or f(a, b, c) > 100):
	a = randint(1, 90)
	b = randint(1, 5)
	c = randint(1, 90)

print(a, b, c, f(a, b, c))