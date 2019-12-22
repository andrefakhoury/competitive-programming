MAXN = int(2e4)
M = int(1e9 + 7)

fac = [1, 1]
for i in range(2, MAXN):
	fac.append((fac[i-1] * i) % M)

def powerMod(x, y, m):
	x %= m
	ans = 1

	while (y > 0):
		if (y%2 != 0): ans = (ans * x) % m
		x = (x * x) % m
		y = y // 2
	return ans;

def inv(n):
	return powerMod(n, M - 2, M)

memo = {}

def nck(n, k):
	if k > n: return 0

	if (n * 4384 + k * 90210 in memo): return memo[n * 4384 + k * 90210]
	memo[n * 4384 + k * 90210] = (((fac[n] * inv(fac[n-k])) % M) * inv(fac[k])) % M
	return memo[n * 4384 + k * 90210]

T = int(raw_input())
for cs in range(1, T+1):
	N, K = map(int, raw_input().split())
	A = list(map(int, raw_input().split()))
	A.sort()

	ans = 0
	for i in range(N):
		ans = (ans + A[i] * nck(i + 1, K) * K * inv(i + 1)) % M

	print("Case #{}: {}".format(cs, ans))