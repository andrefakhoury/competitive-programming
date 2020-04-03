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
	int n; rd(n);
	vector<int> a(n);
	for (auto& i : a) rd(i);

	set<int> bl, br;
	
	set<int> cur;
	for (int i = 0; i < n; i++) {
		if (cur.count(a[i])) {
			break;
		} else {
			cur.emplace(a[i]);
			if (cur.size() == *cur.rbegin()) {
				bl.emplace(i);
			}
		}
	}

	cur.clear();
	for (int i = n-1; i >= 0; i--) {
		if (cur.count(a[i])) {
			break;
		} else {
			cur.emplace(a[i]);
			if (cur.size() == *cur.rbegin()) {
				br.emplace(i);
			}
		}
	}

	vector<pii> ans;
	for (int i : bl) {
		if (br.count(i+1)) {
			ans.eb(i+1, n-i-1);
		}
	}

	cout << ans.size() << "\n";
	for (auto p : ans) {
		cout << p.fi << " " << p.se << "\n";
	}


}

int main() {
	int __T__; rd(__T__);
	while(__T__--) _solve_();
	return 0;
}