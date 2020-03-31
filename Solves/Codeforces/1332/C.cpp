#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline void _solve_() {
	int n, k; cin >> n >> k;
	string s; cin >> s;
	int nk = n/k;

	set<int> positions;
	for (int i = 0, j = k-1; i <= j; i++, j--) {
		map<char, set<int>> frq;

		for (int cc = 0; cc < nk; cc++) {
			frq[s[i+cc*k]].emplace(i+cc*k);
			frq[s[j+cc*k]].emplace(j+cc*k);
		}
		char mfrq = s[i];
		for (auto p : frq) {
			if (p.se.size() > frq[mfrq].size()) {
				mfrq = p.fi;
			}
		}

		for (auto p : frq) {
			if (p.fi == mfrq) continue;
			for (auto x : p.se) {
				positions.emplace(x);
			}
		}
	}

	cout << positions.size() << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	while(__T__--) _solve_();
	return 0;
}