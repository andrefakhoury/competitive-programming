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

const int MAXN = 1e5;
using bts = bitset<MAXN>;

struct Trie {
	bts bt;
	int end_here;
	Trie *mp[27];

	Trie() : bt{}, end_here(0) {
		mset(mp, 0);
	}

	void add(string const& s, int i, int idx) {
		if (i == (int) s.size()) bt[idx] = 1;
		else {
			const int c = s[i] == '_' ? 0 : s[i] - 'a' + 1;
			if (mp[c] == NULL) mp[c] = new Trie();
			mp[c]->add(s, i + 1, idx);
		}
	}

	bts get(string const& s, int i) {
		if (i == (int) s.size()) return bt;
		if (mp[0] && mp[s[i]-'a'+1]) return mp[0]->get(s, i+1) | mp[s[i]-'a'+1]->get(s, i+1);
		if (mp[s[i]-'a'+1]) mp[s[i]-'a'+1]->get(s, i+1);
		if (mp[0]) mp[0]->get(s, i+1);
		return {};
	}

	~Trie() {
		for (int i = 0; i < 27; i++) {
			if (mp[i]) delete mp[i];
		}
	}
};

inline void run_test(int test_number) {
	int n, m, k; rd(n, m, k);
	vector<string> pat(n);
	for (int i = 0; i < n; i++) rd(pat[i]);

	vector<pair<string, int>> str(m);
	for (int i = 0; i < m; i++) rd(str[i].fi, str[i].se);

	Trie root;
	for (int i = 0; i < n; i++) root.add(pat[i], 0, i);

	vector<bts> matches(m);
	for (int i = 0; i < m; i++) matches[i] = root.get(str[i].fi, 0);

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}