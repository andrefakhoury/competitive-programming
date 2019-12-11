// amortizadamente O(n)

#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<pair<int, int>, int> ppi;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, q; cin >> n >> q;
	set<ppi> bkt = {{{1, n}, 0}};

	while(q--) {
		int l, r, c; cin >> l >> r >> c;
		auto it = bkt.upper_bound({{l, 0x3f3f3f3f}, 0x3f3f3f3f}); it--;
		
		vector<ppi> toErase;
		vector<ppi> toInsert;

		for (auto it2 = it; it2 != bkt.end(); it2++) {
			auto cur = *it2;
			if (cur.fi.fi > r) break;

			if (cur.fi.fi < l) toInsert.emplace_back(ppi({cur.fi.fi, l-1}, cur.se));
			if (cur.fi.se > r) toInsert.emplace_back(ppi({r+1, cur.fi.se}, cur.se));
			toErase.emplace_back(cur);
		}

		for (auto p : toErase) bkt.erase(p);
		for (auto p : toInsert) bkt.emplace(p);

		ppi at = {{l, r}, c};
		bkt.emplace(at);
	}

	for (auto& p : bkt)	{
		for (int i = p.fi.fi; i <= p.fi.se; i++)
			cout << p.se << '\n';
	}
}