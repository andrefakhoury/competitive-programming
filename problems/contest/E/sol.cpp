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

const int MAXN = 3e5 + 5;
int a[MAXN];

inline void run_test(int test_number) {
	int n, q; rd(n, q);
	for (int i = 1; i <= n; i++) rd(a[i]);

	auto find_group = [](int x) {
		if (x == 1) return 0;
		if (x & 1) return 1;
		return 2;
	};

	ll ans = 0;
	set<int> idx[3]; // [0]: 1, [1]: 1 setado, [2]: 1 nao setado
	for (int i = 1; i <= n; i++) {
		idx[find_group(a[i])].insert(i);
		ans += a[i];
	}

	auto go = [&](int l, int r, int old, int op) {
		vector<int> to_erase;
		for (auto it = idx[old].lower_bound(l); it != idx[old].end() && *it <= r; it++) {
			int new_a;
			if (op == 1) new_a = a[*it] | (a[*it] - 1);
			else new_a = a[*it] ^ (a[*it] - 1);

			ans += new_a - a[*it];
			idx[find_group(new_a)].insert(*it);
			a[*it] = new_a;

			to_erase.push_back(*it);
		}

		for (int x : to_erase) idx[old].erase(x);
	};

	while(q--) {
		int op, l, r; rd(op, l, r);
		if (op == 1) go(l, r, 2, 1);
		else {
			go(l, r, 1, 2);
			go(l, r, 2, 2);
		}

		print(ans);
	}
}

int main() {

#ifndef LOCAL_PC
	freopen("orxor.in", "r", stdin);
#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}