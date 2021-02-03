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

const int ALPHA_SIZE = 2;
struct Trie {
	int cnt, end_here;
	Trie* children[ALPHA_SIZE] = {};

	Trie() : cnt{}, end_here{}, children{} { }

	template<typename T> inline static int get_val(T const& s, int i) {
		return bool(s & (1 << i));
	}

	template<typename T> void add(T const& s, int i = 25) {
		if (i == -1) end_here++;
		else {
			cnt++;
			int cur_val = get_val(s, i);
			if (children[cur_val] == NULL) children[cur_val] = new Trie();
			children[cur_val]->add(s, i - 1);
		}
	}

	int solve(int val, bool all = false, int i = 25) { // quantos caras tem >= val
		if (all) return cnt;

		if (i == -1) return end_here;
		int cur_val = get_val(val, i);

		int ans = 0;
		if (cur_val) {
			if (children[1]) ans += children[1]->solve(val, false, i - 1);
		} else {
			if (children[0]) ans += children[0]->solve(val, false, i - 1);
			if (children[1]) ans += children[1]->solve(val, true, i - 1);
		}

		return ans;
	}

	~Trie() { for (int i = 0; i < ALPHA_SIZE; i++) delete children[i]; }
};

inline void run_test(int test_number) {
	int n, k; rd(n, k);
	vector<int> a(n + 1);
	vector<int> p(n + 1);
	Trie t;

	for (int i = 1; i <= n; i++) {
		rd(a[i]);
		p[i] = a[i] ^ p[i - 1];
		cerr << bitset<3>(p[i]) << " === " << p[i] << "\n";
	}

	ll ans = 0;
	for (int i = n; i >= 1; i--) {
		t.add(p[i]);
		cerr << "added " << (p[i] ^ k) << "\n";
		ans += t.solve(p[i - 1] ^ k);
	}

	print(ans);
}

int main() {

//#ifndef LOCAL_PC
//	freopen("FILE.in", "r", stdin);
//#endif

	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	rd(n_tests);
	for (int i = 1; i <= n_tests; i++) run_test(i);
}