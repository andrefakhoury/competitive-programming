#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int n;
	while(scanf("%d", &n), n) {
		vector<pii> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].fi);
			a[i].se = i;
		}
		sort(a.begin(), a.end(), [](pii const& x1, pii const& x2)->bool {
			return x1.fi == x2.fi ? x1.fi < x2.fi : x1.fi > x2.fi;
		});

		int k; scanf("%d", &k);
		vector<int> ans(n);
		bool ok = true;

		while(ok && k > 0) {
			for (int i = 0; ok && k > 0 && i < n; i++) {
				if (a[i].fi == 0) continue;
				else {
					a[i].fi--;
					ans[i]++;
					k--;
				}
			}
			bool cc = false;
			for (int i = 0; !cc && i < n; i++) cc = a[i].fi != 0;
			if (k > 0 && !cc) ok = false;
		}

		if (!ok) printf("Impossible\n");
		else for (int i : ans) printf("%d\n", i);
	}

	return 0;
}