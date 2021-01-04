n = int(input())
a = [0] * n

for i in range(n):
    a[i] = int(input())

xx = 0
pt = 1
for i in range(n):
    xx += a[i] * pt
    pt *= 4/5
xx = 1/5 * xx

ans = 0
for i in range(n):
    ret = 0
    pt = 1
    for j in range(n):
        if i != j:
            ret += a[j] * pt
            pt *= 4/5
    ans += ret * 1/5

print(xx)
print(ans/n)