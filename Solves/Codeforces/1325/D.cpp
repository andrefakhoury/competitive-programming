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

inline void imp() {
	cout << -1 << '\n';
	exit(0);
}

inline void answer(vector<ll> a) {
	cout << a.size() << '\n';
	for (ll x : a) cout << x << " ";
	cout << "\n";
	exit(0);
}

inline void can2(ll u, ll v) {
	ll r1 = 0, r2 = 0;

	r1 = u;
	for (ll i = 60; i >= 0; i--) {
		if ((1ll << i) & u) continue;

		ll n1 = r1;
		ll n2 = r2;

		n1 |= 1ll << i;
		n2 |= 1ll << i;

		if (n1 + n2 <= v) {
			r1 = n1;
			r2 = n2;
		}
	}

	if ((r1 + r2) == v && (r1 ^ r2) == u) answer(vector<ll>{r1, r2});
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll u, v; cin >> u >> v;

	if (u > v) imp();

	if (u == 0 && v == 0) {
		cout << 0 << '\n';
		return 0;
	}

	if (u == v) answer(vector<ll>{u});

	can2(u, v);
	if (v - u > 1) {
		ll u1 = (v - u) / 2;
		ll u2 = (v - u) / 2;
		ll u3 = u;

		if ((u1^u2^u3) == u && (u1+u2+u3) == v)
			answer(vector<ll>{u1, u2, u3});
	}

	imp();
	return 0;
}