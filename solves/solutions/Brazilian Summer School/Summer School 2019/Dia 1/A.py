def gcd(a, b):
	return b if a%b == 0 else gcd(b, a%b)

R = input()

if('.' in R):
	inteiro, decimal = R.split('.')
else:
	inteiro = int(R)
	decimal = 0
num = int(inteiro) * 100 + int(decimal)
ans = 36000/gcd(36000, num)

print(int(ans))
