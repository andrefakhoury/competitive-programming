#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

int main() {
	int n, x;

	scanf("%d", &n);

	int negODD = -INF;
	int posODD = INF;
	ll sum = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &x);

		if (x <= 0 && x%2 == 0) continue;

		if (x < 0) negODD = max(negODD, x);
		else {
			if (x%2) posODD = min(posODD, x);
			sum += x;
		}
	}

	if (sum%2 == 0) sum = max(sum+negODD, sum-posODD);
	printf("%lld\n", sum);
}