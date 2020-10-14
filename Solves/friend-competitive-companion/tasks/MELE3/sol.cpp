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

const int N = 50000;
const int K = 1000;

int memo[N][K+1][2];

int main() {
#ifndef LOCAL_PC
	freopen(stdin, "liftovi.in", "r");
	freopen(stdout, "liftovi.out", "w");
#endif
	// memo[E][A][sobe] = menor tempo pra chegar

	int k, n; rd(k, n);
	vector<pii> a(n);

	mset(memo, 0x3f);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi, a[i].se);
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		int l = a[i].fi, r = a[i].se;
		if (l == 1) {
			for (int j = l; j <= r; j++)
				memo[i][j][0] = j - l;
			for (int j = r; j >= l; j--)
				memo[i][j][1] = r - l + r - j;
		}
	}

	// 1 -> 0
	// 2 -> 1
	// 3 -> 2
	// 4 -> 3
	// 5 -> 4
	// 4 -> 5
	// 3 -> 6
	// 2 -> 7
	// 1 -> 8
	// 2 -> 9

	// 


	ll ans = 0x3f3f3f3f3f;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			ans = min(ans, memo[i][k][j]);
		}
	}

	printf("%lld\n", ans * 5);
}