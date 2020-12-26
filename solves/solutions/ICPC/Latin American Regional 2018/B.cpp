#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

int main() {
	int n; scanf("%d", &n);

	set<ll> point = {0};
	ll sum = 0;

	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		sum += x;
		point.insert(sum);
	}

	int cnt = 0;
	for (ll p : point) {
		if (point.count((p + sum/2) % sum)) {
			cnt++;
			point.erase(p);
			point.erase((p + sum/2) % sum);
		}
	}

	printf("%c\n", cnt >= 2 && sum % 2 == 0 ? 'Y' : 'N');
	return 0;
}