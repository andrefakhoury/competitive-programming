#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

using ull = unsigned long long;

unordered_map<ull, int> f;
vector<vector<ull>> v;

void go(int i, ull mask, vector<int> const& a) {
	if (i == (int) a.size()) {
		v.back().pb(mask);
		f[mask]++;
		return;
	}
	go(i + 1, mask, a);
	for (int qt = 0; qt < a[i]; qt++) {
		ull cur_id = (ull)1 << (8 * i + qt);
		mask |= cur_id;
		go(i + 1, mask, a);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	int n, k; rd(n, k);

	while(n--) {
		char c; rd(c);
		if (c == 'C') {
			int ki; rd(ki);

			vector<int> a(k);
			for (int i = 0; i < ki; i++) {
				int x; rd(x);
				a[x-1]++;
			}

			v.emplace_back();
			go(0, 0, a);

		} else if (c == 'J') {
			int ki; rd(ki);
			vector<int> a(k);
			for (int i = 0; i < ki; i++) {
				int x; rd(x);
				a[x-1]++;
			}

			ull mask = 0;
			for (int i = 0; i < k; i++) {
				for (int x = 0; x < a[i]; x++) {
					ull cur_id = (ull)1 << (8 * i + x);
					mask |= cur_id;
				}
			}
			print(f[mask]);
		} else if (c == 'D') {
			int id; rd(id);
			id--;
			for (ull& x : v[id]) f[x]--;
		}
	}


	
}
