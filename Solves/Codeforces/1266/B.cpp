#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

set<ll> sum;

bool _solve(ll x) {
	if (x < 21-6) return false;
	if (sum.count(x)) return true;

	for (ll k : sum) {
		ll topo = k;
		if (x - topo < 0) continue;
		if ((x - topo) % 14 == 0) return true;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 1; i <= 6; i++) {
		sum.emplace(21 - i);
	}

	int t; cin >> t;
	while(t--) {
		ll x; cin >> x;
		bool can = _solve(x);

		cout << (can ? "YES" : "NO") << '\n';
	}


	return 0;
}