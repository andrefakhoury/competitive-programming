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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 1e6 + 1, INF = 0x3f3f3f3f;

vector<int> h[MAXN];
vector<int> hab[MAXN];
vector<int> let[MAXN];

int N;

int main() {
	int n; rd(n);
	vector<pii> a(n);
	vector<int> all;
	for (int i = 0; i < n; i++) {
		rd(a[i].fi, a[i].se);
		all.pb(a[i].fi);
	}

	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());
	auto getx = [&](int k) {
		return lower_bound(all.begin(), all.end(), k) - all.begin();
	};

	N = all.size();
	for (int i = 0; i < n; i++)
		h[getx(a[i].fi)].pb(a[i].se);
	for (int i = 0; i < N; i++) {
		sort(h[i].begin(), h[i].end());
	}

	// primeiro mais proximo
	auto prox1 = [&](int i, int k) {
		auto i1 = lower_bound(h[i].begin(), h[i].end(), k);
		if (i1 == h[i].end()) i1--;
		if (i1 == h[i].begin()) return i1;
		auto i2 = prev(i1);
		if (abs(*i1 - k) > abs(*i2 - k)) return i2;
		return i1;
	};

	// segundo mais proximo
	auto prox2 = [&](int i, int k) {
		auto in = prox1(i, k);
		int id_in = in - h[i].begin();

		auto ans = h[i].end();
		for (int j = max(0, id_in - 3); j < min((int) h[i].size(), id_in + 3); j++) if (j != id_in) {
				if (ans == h[i].end() or abs(*ans - k) > abs(h[i][j] - k))
					ans = h[i].begin() + j;
			}

		return ans;
	};

	for (int i = 0; i < N; i++) {
		using tiii=tuple<int, int, int>;

		if (i != N-1) {
			tiii b1 = {INT_MAX, INT_MAX, INT_MAX}, b2 = {INT_MAX, INT_MAX, INT_MAX};
			auto update = [&](tiii cur) {
				if (b1 > cur) {
					b2 = b1;
					b1 = cur;
				} else if (b2 > cur) {
					b2 = cur;
				}
			};

			for (int id = 0; id < (int) h[i].size(); id++) {
				int x = h[i][id];

				auto it1 = prox1(i+1, x);
				auto it2 = prox2(i+1, x);

				int d1 = abs(*it1 - x);
				int d2 = INT_MAX;
				if (it2 != h[i+1].end()) d2 = abs(*it2 - x);
				update(make_tuple(d1, id, it1 - h[i+1].begin()));
				update(make_tuple(d2, id, it2 - h[i+1].begin()));
			}

			auto go = [&](tiii b) {
				auto [dif, idi, idj] = b;
				if (idi < (int) h[i].size())
					let[i].pb(idi);
				if (idj < (int) h[i+1].size())
					let[i+1].pb(idj);
			};

			go(b1);
			go(b2);
		}

		if (i != 0) {
			tiii b1 = {INT_MAX, INT_MAX, INT_MAX}, b2 = {INT_MAX, INT_MAX, INT_MAX};
			auto update = [&](tiii cur) {
				if (b1 > cur) {
					b2 = b1;
					b1 = cur;
				} else if (b2 > cur) {
					b2 = cur;
				}
			};

			for (int id = 0; id < (int) h[i].size(); id++) {
				int x = h[i][id];

				auto it1 = prox1(i-1, x);
				auto it2 = prox2(i-1, x);

				int d1 = abs(*it1 - x);
				int d2 = INT_MAX;
				if (it2 != h[i-1].end()) d2 = abs(*it2 - x);
				update(make_tuple(d1, id, it1 - h[i-1].begin()));
				update(make_tuple(d2, id, it2 - h[i-1].begin()));
			}

			auto go = [&](tiii b) {
				auto [dif, idi, idj] = b;
				if (idi < (int) h[i].size())
					let[i].pb(idi);
				if (idj < (int) h[i-1].size())
					let[i-1].pb(idj);
			};

			go(b1);
			go(b2);
		}
	}

	for (int i = 0; i < N; i++) {
		sort(let[i].begin(), let[i].end());
		let[i].erase(unique(let[i].begin(), let[i].end()), let[i].end());
		for (int j : let[i]) hab[i].pb(h[i][j]);

		for (int j : hab[i]) {
			printf("%d %d\n", i, j);
		}
	}

	vector<ll> now(100), old(100);
	for (int i = N-2; i >= 0; i--) {
		swap(old, now);
		for (int j = 0; j < (int)hab[i].size(); j++) {
			ll& ret = now[j];

			ret = LLONG_MAX;
			for (int ji = 0; ji < (int) hab[i].size(); ji++) if (i == 0 or ji != j or hab[i].size() == 1u) {
				for (int jj = 0; jj < (int) hab[i+1].size(); jj++) {
					ret = min(ret, abs(hab[i][ji] - hab[i+1][jj]) + old[jj]);
				}
			}
		}
	}

	printf("%lld\n", now[0]);
}