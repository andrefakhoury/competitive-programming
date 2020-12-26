import math


def bb(k, a, b):
	l = 0
	r = 10000 * ((a + b) // b)
	ans = 0
	while l <= r:
		mi = (l + r) // 2
		kk = k + mi * b
		n = (kk * kk + kk) // 2 - (kk-1) * a // b
		if n > 0:
			r = mi-1
			ans = mi
		else:
			l = mi+1
	return ans * b

def go():
	T = int(input())
 
	while T > 0:
		T -= 1
 
		a, b = map(int, input().split())
		g = math.gcd(a, b)
		a //= g
		b //= g

		cnt = 0
		pr=False

		k = b + 1
		if pr: print(cnt)
		while True:
			n = (k * k + k) // 2 - (k-1) * a // b
			if n > k: break
			if n >= 1 and n <= k and b * ((k * (k + 1)//2) - n) == a * (k - 1):
				if pr: print(k, n, flush=False)
				cnt += 1
			if n > 0:
				k += b
			else:
				k += bb(k, a, b)

		pr = True
		k = b + 1
		if pr: print(cnt)
		while True:
			n = (k * k + k) // 2 - (k-1) * a // b
			if n > k: break
			if n >= 1 and n <= k and b * ((k * (k + 1)//2) - n) == a * (k - 1):
				if pr: print(k, n, flush=False)
				cnt += 1
			if n > 0:
				k += b
			else:
				k += bb(k, a, b)
 
if __name__ == "__main__":
	go()