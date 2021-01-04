#include <bits/stdc++.h>
using namespace std;

#define int long long

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

multiset<int> lug;
ll solve(ll i, int t, int s) {
	multiset<int> bag = lug;

	ll ans = 0;
	while(!bag.empty()) {
		auto it1 = bag.lower_bound(i);
		
		bool flag = false;
		if (it1 == bag.end()) {
			it1 = bag.begin();
			flag = true;
		}

		ll nxt = *it1;
		bag.erase(it1);

		if (flag) ans += s - i + nxt + t;
		else ans += nxt - i + t;

		i = (nxt + t) % s;
	}

	return ans;
}

decltype(1) main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, s, t; cin >> n >> s >> t;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		lug.emplace(x);
	}

	ll ans = 0;
	ll best = LLONG_MAX, worst = LLONG_MIN;
	ll ks = 0;
	for (auto i = lug.begin(), iend = lug.end(); i != iend; ++i) {
		ll x = solve(*i, t, s);

		ll fin;
		if (i == lug.begin()) fin = *(--lug.end());
		else fin = *prev(i);

		ll dif;
		if (*i < fin) dif = s - (fin - *i) - 1;
		else dif = *i - fin - 1;

		if (*lug.begin() == *(--lug.end())) dif = s-1;

		best = min(best, x);
		worst = max(worst, x + dif);

		if (i == lug.begin() or fin != *i) {
			ans += (dif+1)*x + (dif+1)*(dif)/2;
			ks += dif+1;
		}
		// best = min(best, solve(i, t, s));
		// worst = max(worst, solve((i+1)%s, t, s));
	}

	cout << best << '\n' << worst << '\n';

	ll g = gcd(ans, s);
	cout << ans/g;
	if (1) cout <<"/" << s/g << "\n";
	else cout << "\n";
	return 0;
}