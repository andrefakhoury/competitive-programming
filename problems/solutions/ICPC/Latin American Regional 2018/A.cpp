#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

int main() {
	int a, b; scanf("%d.%d", &a, &b);

	a = a * 100 + b;
	b = 36000;

	printf("%d\n", b / __gcd(a, b));
}