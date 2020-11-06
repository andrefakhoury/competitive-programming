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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;
const int BK = 200;

int a[MAXN];

ll memo[MAXN];

int main() {

	while(true) {
		int n = 20;
		int k = randint(1, n);
		for (int i = 1; i <= n; i++) a[i] = randint(1, 1000);
		sort(a+1, a+n+1);

		memo[n+1] = 0;
		for (int i = n - k + 1; i >= 1; i--) {
			memo[i] = 1e15;
			for (int j = n - k - i + 1; j >= 0; j--) {
				memo[i] = min(memo[i], max((ll) a[i + j + k - 1] - a[i], memo[i + k + j]));
			}
		}

		ll ans1 = memo[1];

		memo[n+1] = 0;
		for (int i = n - k + 1; i >= 1; i--) {
			memo[i] = 1e15;
			for (int j = min(n - k - i + 1, 1 + (int) sqrt(n)); j >= 0; j--) {
				memo[i] = min(memo[i], max((ll) a[i + j + k - 1] - a[i], memo[i + k + j]));
			}
		}

		if (memo[1] != ans1) {
			printf("%d %d\n", n, k);
			for (int i = 1; i <= n; i++) printf("%d ", a[i]);
			printf("\n");

			printf("%lld vs %lld\n", memo[1], ans1);
		}

		assert(memo[1] == ans1);
	}


	printf("%lld\n", memo[1]);
}
