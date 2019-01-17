#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n; scanf("%d", &n);

	int ans = n;
	for (int i = 1; i < n; i++) {
		ans += i * (n-i);
	}

	printf("%d\n", ans);


	return 0;
}