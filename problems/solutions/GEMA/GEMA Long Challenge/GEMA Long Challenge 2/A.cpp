#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 2e5 + 5;

struct dist {
	ll mini, maxi;
	int id;

	dist() {}
	dist(ll a, ll b, int c) {
		mini = a, maxi = b, id = c;
	}

	bool operator<(const dist& p) {
		return maxi == p.maxi ? mini < p.mini : maxi < p.maxi;
	}
};

void impossible() {
	cout << "No\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;

	vector<pll> inp(n);
	for (int i = 0; i < n; i++)
		cin >> inp[i].fi >> inp[i].se;

	vector<dist> a;
	for (int i = 1; i < n; i++) {
		ll mini = inp[i].fi - inp[i-1].se;
		ll maxi = inp[i].se - inp[i-1].fi;
		a.emplace_back(mini, maxi, i-1);
	}

	map<ll, set<int> > mp;
	for (int i = 0; i < m; i++) {
		ll x; cin >> x;
		mp[x].insert(i + 1);
	}

	sort(a.begin(), a.end());
	vector<int> ans(n - 1);

	for (dist d : a) {
		auto it = mp.lower_bound(d.mini);

		if (it == mp.end()) impossible();
		if (it->first > d.maxi) impossible();
		
		ans[d.id] = *(it->second.begin());

		(it->second).erase(ans[d.id]);
		if ((it->second).empty()) mp.erase(it->first);
	}

	cout << "Yes\n";
	for (int id : ans) cout << id << ' ';
	cout << '\n';
}