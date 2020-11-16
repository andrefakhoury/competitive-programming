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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Trie {
	map<char, Trie> mp;
	bool end = false;
	bool add(string const& s, int i = 0) {
		if (end == true) return false;
		if (i == (int) s.size()) end = true;
		else return mp[s[i]].add(s, i+1);
		return true;
	}
};

inline void _solve_(int __ntest__) {
	int n; cin >> n;
	bool ans = true;
	Trie root;

	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end(), [](string const& a, string const& b) {
		if (a.size() == b.size()) return a < b;
		return a.size() < b.size();
	});

	for (int i = 0; i < n; i++) ans &= root.add(a[i]);
	cout << (ans ? "YES" : "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}