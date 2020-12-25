#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
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

const int MAXN = 1e4 + 5, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;

int n, k, m;

int memo[MAXN][11][11];

int solve(int i, int q, int c) {
	if (q == m) return 0;
	if (i == n) return 1;

	int& ret = memo[i][q][c];
	if (~ret) return ret;

	auto add = [&](int& a, int b) {
		a += b;
		if (a >= MOD) a -= MOD;
	};

	ret = 0;
	for (int color = 1; color <= k; color++) {
		add(ret, solve(i+1, color == c ? q + 1 : 0, color));
	}

	return ret;
}

int main() {
	rd(n, k, m);
	mset(memo, -1);
	printf("%d\n", solve(0, 0, 0));
}
