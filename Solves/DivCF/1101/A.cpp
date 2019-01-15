#include <bits/stdc++.h>
using namespace std;

int main() {
	int q; scanf("%d", &q);
	while(q--) {
		int l, r, d; scanf("%d%d%d", &l, &r, &d);

		long long ans = d < l ? d : (r+d)-((r+d)%d);
		printf("%lld\n", ans);
	}
}
