#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	
	int k; scanf("%d", &k);

	int ans = 0;
	for (int n = 1; n <= 10000; n++) {
		int quadradinhos = n*(n+1)/2;
		k -= quadradinhos;

		if (k < 0) break;
		ans = n;
	}

	return !printf("%d\n", ans);
}
