from math import sqrt, floor, ceil

x, y, r = map(float, input().split(' '))

N = int(3e5)
ans = 0
for k in range(-N, N):
	if r * r >=  (k - y) * (k - y):
		sq = sqrt(r * r - (k - y) * (k - y))
		x1 = sq + x
		x2 = x - sq
		if (x1 > x2): x1, x2 = x2, x1
		ans += floor(x2) - ceil(x1) + 1
print(ans)