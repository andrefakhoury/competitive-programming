#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	int n; rd(n);

	vector<vector<int>> p;
	for (int i = 2; i <= n; i++) {
		int k; rd(k);
		vector<int> cur(k);
		for (int& j : cur) rd(j), j--;
		p.eb(cur);
	}

	vector<set<int>> edges(n);
	map<int, int> freq;

	for (auto& v : p) {
		for (int& i : v) {
			freq[i]++;
		}

		for (int i : v) {
			for (int j : v) {
				if (i != j) edges[i].emplace(j);
			}
		}
	}

	vector<pii> pos_freq(n);
	for (int i = 0; i < n; i++) {
		if (i == 0 or i == n-1) pos_freq[i].fi = 1;
		else pos_freq[i].fi = 2;
		pos_freq[i].se = n - i;
	}

	vector<int> a(n);

	for (int i = 0; i < n; i++) {
		if (freq[i] == 1) { // primeiro ou ultimo
			if (edges[*edges[i].begin()].size())
			if ()

		}
	}




}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}