#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
typedef long long ll;

ll len[MAXN];

int main() {
	ll n, k, l, m; scanf("%lld%lld%lld", &n, &k, &l);
	m = n*k;

	for (int i = 0; i < m; i++) {
		scanf("%lld", len+i);
	}

	sort(len, len+m);
	vector<ll> ans = {len[0]};

	int cur = 0;
	for (int i = m-1; i > 0; i--) {
		cur++;

		if (cur >= k && len[i] - ans[0] <= l) {
			cur -= k;
			ans.push_back(len[i]);
		}
	}

	if (ans.size() < n) return !printf("0\n");
	ll sum = 0;
	for (int i = 0; i < n; i++) sum += ans[i];
	printf("%lld\n", sum);
}