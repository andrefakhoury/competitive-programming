#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cout << #x << ": " << x << endl)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define int ll

const int N = 757, M = 1e9 + 7;
int mat[N][N];

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int k, l; cin >> k >> l;

	for(int i = 1; i <= k; i++) {
		for(int j = 1; j <= k; j++) {
			cin >> mat[i][j];
		}
	}

	int n; cin >> n;

	vector<int> p(n);
	for(int i = 0; i + 1 < n; i++) {
		cin >> p[i];
	}

	vector<int> f(k+1), pref(k+1);

	for(int i = 1; i <= k; i++) {
		f[i] = 1;
		pref[i] = i;
	}

	auto query = [&](int l, int r) {
		if(l > r) return 0ll;
		assert(l);
		return (pref[r] - pref[l-1] + M)%M;
	};
	// for(int j = 1; j <= k; ++j)
	// 		cout << f[j] << ' ';
	// 	cout << endl;

	for(int i = n-2; i >= 0; i--) {

		for(int j = 1; j <= k; ++j) {
			int Ll = lower_bound(mat[j] + 1, mat[j] + 1 + k, p[i] - l) - mat[j];
			int rr = upper_bound(mat[j] + 1, mat[j] + 1 + k, p[i] + l) - mat[j];

			f[j] = query(Ll, rr-1);
			// deb(Ll);
			// deb(rr);
			// deb(query(Ll, rr-1));
		}

		for(int j = 1; j <= k; ++j)
			pref[j] = (f[j] + pref[j-1])%M;

		// for(int j = 1; j <= k; ++j)
		// 	cout << f[j] << ' ';
		// cout << endl;
	}

	ll ans = 0;
	for(int i = 1; i <= k; i++) {
		ans += f[i];
		ans %= M;
	}

	cout << ans << '\n';


}