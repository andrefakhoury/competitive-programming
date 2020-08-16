#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
//	freopen("trapped.in", "r", stdin);
//	freopen("trapped.out", "w", stdout);

	int n; scanf("%d", &n);
	vector<pii> a(n);
	for (pii& i : a) scanf("%d%d", &i.fi, &i.se);

	sort(a.begin(), a.end(), [](pii a, pii b) {
		return a.se < b.se;
	});

	int L = a.front().se, R = a.back().se;

	vector<tuple<int, int, int>> range(n); // <position, dl, dr>
	set<tuple<int, int, int, int>> st; // <max difference, dl, dr, index>
	set<int> active;
	for (int i = 0; i < n; i++) {
		int dl = a[i].se - (i ? a[i-1].se : L);
		int dr = (i+1 < n ? a[i+1].se : R) - a[i].se;
		range[i] = make_tuple(a[i].se, dl, dr);
		st.emplace(a[i].fi - max(dl, dr), dl, dr, i);
		active.insert(i);
	}

	while(st.size() && get<0>(*st.begin()) < 0) {
		int dd, dl, dr, index;
		tie(dd, dl, dr, index) = *st.begin();
		assert(dd < 0);
		st.erase(st.begin());
		active.erase(index);
		if (st.empty()) continue;

		DBG(index);
		DBG(dl);
		DBG(dr);
		cerr << endl;

		// atualiza o da esquerda
		auto itl = active.upper_bound(index);
		if (itl != active.begin()) {
			int left = *prev(itl), ldl, ldr, newdif, pos;
			tie(pos, ldl, ldr) = range[left];
			newdif = a[left].fi - max(ldl, ldr);
			st.erase(make_tuple(newdif, ldl, ldr, left));

			assert(ldr == dl);

			ldr = dl + dr;
			newdif = a[left].fi - max(ldl, ldr);
			st.emplace(newdif, ldl, ldr, left);
		}

		// atualiza o da direita
		auto itr = active.upper_bound(index);
		if (itr != active.end()) {
			int right = *itr, rdl, rdr, newdif, pos;
			tie(pos, rdl, rdr) = range[right];
			newdif = a[right].fi - max(rdl, rdr);
			st.erase(make_tuple(newdif, rdl, rdr, right));

			assert(rdl == dr);

			rdl = dl + dr;
			newdif = a[right].fi - max(rdl, rdr);
			st.emplace(newdif, rdl, rdr, right);
		}
	}

	if (st.size() <= 1u) {
		puts("0");
	} else {
		int mn = INT_MAX, mx = INT_MIN;
		for (auto p : st) {
			mn = min(mn, get<0>(range[get<3>(p)]));
			mx = max(mx, get<0>(range[get<3>(p)]));
		}
		printf("%d\n", mx - mn);
	}
}