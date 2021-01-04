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

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int memo[MAXN][3];
int a[MAXN][3];

int main() {
	int n; rd(n);
	for (int i = 1; i <= n; i++) for (int j = 0; j < 3; j++)
		rd(a[i][j]);

	int ans = 0;
	for (int i = n; i >= 1; i--) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) if (k != j)
				memo[i][j] = max(memo[i][j], a[i][j] + memo[i+1][k]);
			ans = max(ans, memo[i][j]);
		}
	}

	printf("%d\n", ans);
}