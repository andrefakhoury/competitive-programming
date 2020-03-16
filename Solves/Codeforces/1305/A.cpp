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

inline void _solve() {
	int n; cin >> n;
	vector<pair<ll, int> > a(n), b(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i].fi;
		a[i].se = i + 1;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i].fi;
		b[i].se = i + 1;
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for (int i = 0; i < n; i++) cout << a[i].fi << ' ';
	cout << '\n';
	for (int i = 0; i < n; i++) cout << b[i].fi << ' ';
	cout << '\n';

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}