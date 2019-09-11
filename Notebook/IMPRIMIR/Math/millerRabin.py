# x^y mod MOD
def powerMod(x, y, MOD): # O(logY)
	x %= MOD
	ans = 1

	while (y > 0):
		if (y%2 != 0): ans = (ans * x)%MOD
		y = y/2

		x = (x * x) % MOD

	return ans;

# miller rabin primality test of N, according to the bases of the vector
def isProbablePrime(n, bases):
	if (n > 2 and n%2 == 0): return 0
	if (n > 3 and n%3 == 0): return 0
	if (n > 5 and n%5 == 0): return 0
	if (n > 7 and n%7 == 0): return 0

	# n = 2^k * q + 1 
	k = 0
	q = n-1

	while (q > 0 and q%2 == 0):
		k = k+1
		q = q/2

	for b in bases:
		if (n == b): continue

		last = -1
		p2 = 1

		for j in range(0, k+1):
			cur = powerMod(b, p2 * q, n)
			p2 = p2 * 2

			if (last != -1):
				if (last == n-1 and cur != 1): return 0
				if (last == 1 and cur != 1): return 0

			last = cur

		if (last != 1): return 0

	return 1

def main():
	bases = [2, 3, 7, 37]
	while(1 != 0):
		n = int(input())
		print(isProbablePrime(n, bases))

main()