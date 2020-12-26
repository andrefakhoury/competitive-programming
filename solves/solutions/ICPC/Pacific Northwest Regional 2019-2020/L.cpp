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

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

inline void imp() {
	cout << -1 << '\n';
	exit(0);
}

int n, m;
vector<int> s;
vector<int> cur;
vector<vector<pii> > mul;

inline void answer() {
	for (int x : cur) cout << x;
	cout << "\n";
	exit(0);
}

void solve(int i) {
	if (i == n) answer();

	if (i >= m) {
		
		bool ok = true;
		int sum = 0;
		for (auto p : mul[i])
			sum = (sum + cur[p.fi] * cur[p.se]) % 10;
		ok = sum == s[i];
		if (!ok) return;
		else solve(i+1);

	} else {
		for (int d = 0; d <= 9; d++) {
			cur.eb(d);

			bool ok = true;
			int sum = 0;
			for (auto p : mul[i]) {
				sum = (sum + cur[p.fi] * cur[p.se]) % 10;
			}

			ok = sum == s[i];

			if (ok) solve(i+1);
			cur.pop_back();
		}
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string xx; cin >> xx;
	n = xx.size();
	for (int i = 0; i < n; i++) s.eb(xx[i]-'0');
	if (n % 2 == 0) imp();

	m = (n + 1)/2;

	mul = vector<vector<pii> >(n);

	for (int d = 0; d < (n+1)/2; d++) {
		for (int i = 0; i < (n+1)/2; i++) {
			mul[i+d].eb(d, i);
		}
	}

	solve(0);
	imp();
}