#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cout << #x << ' ' << x << endl)

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, m, k; 
vector<int> active;

ll calc(vector<ii> & X) {
	ll ans = 0;
	int tot = 0;
	for(int r, l = 0; l < k; l = r) {
		r = l;
		while(r < k and X[r].fi == X[l].fi) {
			tot ^= active[X[r].se];
			r++;
		}
		ll mul = (r == k? m + 1 : X[r].fi) - X[l].fi;
		if(tot) ans += mul;
	}
	return ans;
}

void _solve() {
	cin >> n >> m >> k;


	vector<ii> Y, X;
	active.assign(k + 32, 0);

	for(int i = 0; i < k; ++i) {
		int p, q; cin >> p >> q;

		Y.eb(p, i);
		X.eb(q, i);
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());


	ll ans = 0;
	for(int r, l = 0; l < k; l = r) {
		r = l;

		while(r < k and Y[r].fi == Y[l].fi) {
			active[Y[r].se] = 1; // ativa o cara
			r++;
		}
		ll mul = (r == k? n + 1 : Y[r].fi) - Y[l].fi; // multiplicador
		ans += mul * calc(X);
	}

	cout << ans << ' ' << (ll) n * m - ans << '\n';
}


int main() {
	freopen("dull.in", "r", stdin);
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;

	while(t--) {
		_solve();
	}
}