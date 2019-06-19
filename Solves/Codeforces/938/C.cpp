#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

const int MAXN = 1e9;

ll f(ll n, ll m) {
	return n*n - (n/m) * (n/m);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		int x; cin >> x;

		for (int nm = 1; nm < MAXN; nm++) {
			int n = x
			
		}
	}
}