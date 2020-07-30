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
#ifndef __linux
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

const int MAXN = 4e3 + 5, INF = 0x3f3f3f3f;

short memo[MAXN][MAXN];
int szs[MAXN];
int N;

bool solve(int i, int sum, int n) {
	if (sum == n) return true;
	if (i == N) return false;
	if (sum > n) return false;

	short& ret = memo[i][sum];
	if (~ret) return ret;

	ret = solve(i+1, sum, n);
	ret |= solve(i+1, sum + szs[i], n);

	return ret;
}

inline void _solve_(int __ntest__) {
	int n; rd(n);
	vector<int> a(n+n);
	for (int& i : a) rd(i);

	vector<vector<int>> all;
	for (int i = 0, m = 0; i < n+n; i++) {
		if (a[i] > m) all.emplace_back();
		all.back().pb(a[i]);
		m = max(a[i], m);
	}

	bool ok = true;

	N = 0;
	for (vector<int> const& v : all) {
		if ((int) v.size() > n) ok = false;
		szs[N++] = v.size();
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= n; j++) {
			memo[i][j] = -1;
		}
	}
	
	ok &= solve(0, 0, n);

	if (ok) puts("YES");
	else puts("NO");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}