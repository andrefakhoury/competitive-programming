#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;

const int MAXN = 1e5 + 5;

ll a[MAXN], sum[MAXN];
pli bnd[MAXN];

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		memset(bnd, 0, sizeof(bnd));

		int n, d; scanf("%d%d", &n, &d);
		
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a+i);
			sum[i] = sum[i-1] + a[i];
		}

		int lo = 0, hi = 1, ans = INT_MAX;
		bnd[0] = mp(0, 0);

		for (int i = 1; i <= n; i++) {
			int ind = lower_bound(bnd+lo, bnd+hi, pli(sum[i] - d, INT_MAX)) - (bnd + 1);
			if (ind >= lo) ans = min(ans, i - bnd[ind].se);
			while(lo < hi && bnd[hi-1].fi >= sum[i]) hi--;
			bnd[hi++] = mp(sum[i], i);			
		}

		printf("%d\n", ans == INT_MAX ? -1 : ans);
	}
}