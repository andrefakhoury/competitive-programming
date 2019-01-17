#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100005;

struct knight {
	int p, c, id;
	ll ans;
};

bool cmp1(knight& a, knight& b) {
	if (a.p == b.p) return a.c > b.c;
	return a.p < b.p;
}

bool cmp2(knight& a, knight& b) {
	return a.id < b.id;
}

int main() {
	int n, k; scanf("%d%d", &n, &k);
	vector<knight> kn(n);

	for (int i = 1; i <= n; i++) scanf("%d", &(kn[i-1].p));
	for (int i = 1; i <= n; i++) scanf("%d", &(kn[i-1].c));
	for (int i = 1; i <= n; i++) kn[i-1].id = i;
	for (int i = 1; i <= n; i++) kn[i-1].ans = 0;

	sort(kn.begin(), kn.end(), cmp1);

	priority_queue<int> prize;
	ll val = 0;

	for (int i = 0; i < n; i++) {
		kn[i].ans = val + kn[i].c;

		if (prize.size() < k) {
			prize.push(-kn[i].c);
			val += kn[i].c;
		} else if (prize.size() > 0) {
			int cur = -prize.top();

			if (cur > kn[i].c) continue;
			val -= cur;
			prize.pop();
			prize.push(-kn[i].c);
			val += kn[i].c;
		}
	}


	sort(kn.begin(), kn.end(), cmp2);
	for (int i = 0; i < n; i++) printf("%lld ", kn[i].ans);
	return !printf("\n");
}
