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
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll a[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a+1, a+n+1);

	vector<ll> neg, pos;
	int qttZero = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] < 0) neg.eb(a[i]);
		if (a[i] > 0) pos.eb(a[i]);
		if (a[i] == 0) qttZero++;
	}

	ll qttNeg = neg.size() * ll(pos.size());
	if (qttNeg >= k) { // RESULTADO NEGATIVO
		// negativo com positivo

		for (int i = 0; i < (int)neg.size(); i++) {
			int lo = 0, hi = (int)pos.size(), mi;
			while(lo < hi) {
				mi = (lo + hi) / 2;
				
			}
		}

		vector<ll> all;
		for (ll nn : neg) {
			for (ll pp : pos) {
				all.eb(nn * pp);
			}
		}
		sort(all.begin(), all.end());
		cout << all[k-1] << '\n';

	} else if (qttNeg + qttZero >= k) { // ZERO
		cout << 0 << endl;
	} else { // RESULTADO POSITIVO
		// negativo com negativo
		// positivo com negativo
	}

	return 0;
}