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

inline ll lcm(ll a, ll b) {
	return a * (b / __gcd(a, b));
}

inline void solve(ll x) {
	ll best = LLONG_MAX, x1 = -1, x2 = -1;

	for (ll i = 1; i * i <= x; i++) {
		if (x%i == 0 && max(i, x/i) < best && lcm(i, x/i) == x) {
			best = max(i, x/i);
			x1 = i;
			x2 = x/i;
		}

	}

	cout << x1 << ' ' << x2 << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	ll x; cin >> x;
	solve(x);
	return 0;
}