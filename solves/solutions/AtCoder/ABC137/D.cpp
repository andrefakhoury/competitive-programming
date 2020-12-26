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
	
	int n, m; cin >> n >> m;
	vector<pii> a(n);
	for (auto& p : a) cin >> p.fi >> p.se;

	set<int> days;
	for (int i = 1; i <= m; i++) days.emplace(i);

	sort(a.begin(), a.end(), [](pii const& x, pii const& y) {
		return x.se == y.se ? x.fi < y.fi: x.se > y.se;
	});

	ll ans = 0;
	for (auto p : a) {
		if (days.empty()) break;
		auto it = days.upper_bound(m - p.fi + 1);
		if (it != days.begin()) {
			it--;
			days.erase(it);
			ans += p.se;
		}
	}

	cout << ans << '\n';

	return 0;
}