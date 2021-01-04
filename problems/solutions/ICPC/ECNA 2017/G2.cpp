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

int memo[101][101];
int val[101];
int a[101];
int n;

int solve(int i, int m) {
	if (i == n) return 0;

	int& ret = memo[i][m];
	if (~ret) return ret;

	ret = min(val[m], a[i]) + solve(i + 1, m + 1); // escolhe comer
	ret = max(ret, solve(i + 1, max(m - 1, 0)));

	return ret;
}

int main() {
	mset(memo, -1);

	int m; rd(n, m);
	for (int i = 0; i < n; i++) rd(a[i]);
	val[0] = m;
	for (int i = 1; i <= n; i++) val[i] = 2 * val[i-1] / 3;
	printf("%d\n", solve(0, 0));
}