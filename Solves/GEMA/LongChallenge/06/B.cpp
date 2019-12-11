#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN];

vector<pii> maxi[MAXN], mini[MAXN];

int main() {
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	int l = a[1];
	maxi[l].eb(1, 1);

	for (int i = 2; i <= n; i++) {
		if (a[i] > l) {
			l = a[i];
			maxi[l].eb(i, i);
		}
		
		maxi[l].se = i;
	}

	minil[0] = minir[n+1] = 1e7;

	for (int i = 1, l = 0; i <= n; i++) {
		maxil[i] = max(a[i], maxil[i-1]);
		if (maxil[i-1] <= a[i]) l = i;
		maxi[l].se = i;
	}

	for (int i = 1, l = 0; i <= n; i++) {
		minil[i] = min(a[i], minil[i-1]);
		if (minil[i-1] >= a[i]) l = i;
		mini[l].se = i;
	}

	for (int i = n, l = n+1; i >= 1; i--) {
		minir[i] = min(a[i], minir[i+1]);
		if (minir[i+1] >= a[i]) l = i;
		mini[l].fi = i;
	}

	for (int i = n, l = n+1; i >= 1; i--) {
		maxir[i] = max(a[i], maxir[i+1]);
		if (maxir[i+1] <= a[i]) l = i;
		maxi[l].fi = i;
	}

	for (int i = 1; i <= n; i++) {
		ll M = maxi[i].se - maxi[i].fi + 1;
		ll N = mini[i].se - mini[i].fi + 1;

		printf("[%d,%d] %lld, [%d,%d] %lld\n", mini[i].fi, mini[i].se, N*(N+1)/2, maxi[i].fi, maxi[i].se, M*(M+1)/2);
	}

	ll ans = 0;
	for (int i = 1; i <= n; i++) {
		ll N = maxi[i].se - maxi[i].fi + 1;
		ans += a[i] * (N * (N + 1) / 2);

		ll M = mini[i].se - mini[i].fi + 1;
		ans -= a[i] * (M * (M + 1) / 2);
	}

	printf("%lld\n", ans);
	return 0;
}