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

struct SuffixAutomaton {
	struct State {
		int len, link;
		map<char, int> next;
	};

	vector<State> st;
	int last;

	SuffixAutomaton(string const& s) {
		int n = s.size();
		st.reserve(2 * n);

		st.push_back(State{0, -1});
		last = 0;

		for (int i = 0; i < n; i++) { // extend current char
			st.push_back(State{i + 1, 0});
			int r = (int) st.size() - 1;

			int p = last;
			while(p >= 0 && st[p].next.find(s[i]) == st[p].next.end()) {
				st[p].next[s[i]] = r;
				p = st[p].link;
			}

			if (p != -1) {
				int q = st[p].next[s[i]];
				if (st[p].len + 1 == st[q].len) {
					st[r].link = q;
				} else { // split and add q'
					st.push_back(State{st[p].len + 1, st[q].link, st[q].next});
					int qq = (int) st.size() - 1;

					st[q].link = st[r].link = qq;
					while(p >= 0 && st[p].next[s[i]] == q) {
						st[p].next[s[i]] = qq;
						p = st[p].link;
					}
				}
			}

			last = r;
		}
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	string s; rd(s);
	SuffixAutomaton sa(s);

	int q; rd(q);
	while(q--) {
		string t; rd(t);
		bool ans = true;

		int p = 0;
		for (int i = 0; i < (int) t.size(); i++) {
			if (sa.st[p].next.count(t[i])) {
				p = sa.st[p].next[t[i]];
			} else {
				ans = false;
				break;
			}
		}

		print("NY"[ans]);
	}
}