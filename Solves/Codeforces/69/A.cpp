#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int a, b, c, x, y, z;
	x = y = z = 0;
	while(n--) {
		scanf("%d%d%d", &a, &b, &c);
		x += a; y += b; z += c;
	}
	printf("%s\n", (!x && !y && !z) ? "YES" : "NO");
}