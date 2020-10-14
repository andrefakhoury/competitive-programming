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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Trie {
	map<char, Trie> mp;
	bool ended = false;

	void add(string const& s, int i = 0) {
		if (i == (int) s.size()) ended = true;
		else mp[s[i]].add(s, i + 1);
	}

	void push(string& s, vector<string>& ans) {
		if (ended) ans.push_back(s);

		for (auto p : mp) {
			s += p.first;
			p.se.push(s, ans);
			s.pop_back();
		}
	}

	void solve(string const& s, vector<string>& ans, int i = 0) {
		if (i == (int) s.size()) { // just add everything that I can
			string x;

			for (auto p : mp) {
				x = s + p.fi;
				p.se.push(x, ans);
			}
		} else if (mp.count(s[i])) {
			mp[s[i]].solve(s, ans, i + 1);
		}
	}


} root;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	while(n--) {
		string s; cin >> s;
		root.add(s);
	}

	int q; cin >> q;
	for (int i = 1; i <= q; i++) {
		string s; cin >> s;
		vector<string> ans;
		root.solve(s, ans);

		cout << "Case #" << i << ":\n";
		if (ans.empty()) {
			cout << "No match.\n";
		} else {
			sort(ans.begin(), ans.end());
			for (string const& x : ans) cout << x << "\n";
		}
	}


}