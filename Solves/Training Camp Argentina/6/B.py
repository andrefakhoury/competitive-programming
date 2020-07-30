import sys

for line in sys.stdin:
	if line == '=\n':
		break

	expr = "int('"
	m = 2

	ok = True
	for c in line:
		if c >= '0' and c <= '9':
			if not ok:
				expr += "int('"
				ok = True
			expr += c
			m = max(m, int(c) + 1)
		else:
			expr += "', b)"
			ok = False
			expr += c
			if c == '=':
				expr += '='

	ans = [0] * 37
	for b in range(m, 37):
		ans[b] = eval(expr)
	if (sum(ans) == 0):
		print('*', flush=False)
	else:
		if (ans[-1] == 1):
		    for i in range(m, 37):
		        if ans[i]:
		            print(f'{i}+', flush=False)
		            break
		else:
			for i in range(m, 37):
				if ans[i]:
					print(i, end=' ', flush=False)
			print('', flush=False)