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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n; cin >> n;
	vector<string> a(n);
	for (auto& x : a) cin >> x;

	map<string, int> f;
	for (auto& x : a) {
		sort(x.begin(), x.end());
		f[x]++;
	}

	ll ans = 0;
	for (auto p : f) {
		ll x = p.se;
		ans += x * (x-1) / 2;
	}

	cout << ans << '\n';

	return 0;
}