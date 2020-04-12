#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
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

const int MAXN = 2e5 + 5;
const ll INF = 0x3f3f3f3f3f3f3f;

ll pas[505][505];
ll acc[505][505];

inline void _solve_() {
	ll x; rd(x);
	ll orig = x;

	int n = 0, k = 1;
	vector<pii> ans;
	for (int i = 0; x > 0; i++) {
		if (i <= 30 && x >= (1 << i)) {
			x -= (1 << i);
			n++;
			if (k == n-1) {
				k = n;
				while(k >= 1) {
					ans.eb(n, k);
					k--;
				}
				k = 1;
			} else {
				while(k <= n) {
					ans.eb(n, k);
					k++;
				}
				k = n;
			}
		} else {
			n++;
			x--;
			if (k == n-1) k = n;
			ans.eb(n, k);
			if (x == 0) break;
			if (x == 1) {
				x--;
				ans.eb(n+1, k == 1 ? 1 : n + 1);
				break;
			}

			int I;
			for (I = 1; I <= n; I++) {
				if (acc[n][I+1] - 1 + acc[n+1][I+1] > x) break;
			}
			if (I == 1) continue;

			// vou ate o i
			x -= acc[n][I] - 1 + acc[n+1][I];
			if (k != 1) {
				k--;
				while(k >= n - I + 1) ans.eb(n, k--);
				k = n - I + 2;
				n++;
				while(k <= n) ans.eb(n, k++);
				k = n;
			} else {
				k++;
				while(k <= I) ans.eb(n, k++);
				k = I;
				n++;
				while(k >= 1) ans.eb(n, k--);
				k = 1;
			}
		}
	}

	assert(x == 0);
	debug("%ld\n", ans.size());
	assert(ans.size() <= 500u);

	ll curr = 0;
	for (auto p : ans) {
		printf("%d %d\n", p.fi, p.se);
		curr += pas[p.fi][p.se];
	}

	assert(curr == orig);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;

	for (int i = 1; i <= 500; i++) pas[i][1] = pas[i][i] = 1;
	for (int i = 2; i <= 500; i++) {
		for (int j = 2; j < i; j++) {
			pas[i][j] = pas[i-1][j] + pas[i-1][j-1];
			pas[i][j] = min(pas[i][j], (ll)INF);
		}
	}

	for (int i = 1; i <= 500; i++) {
		for (int j = 1; j <= i; j++) {
			acc[i][j] = acc[i][j-1] + pas[i][j];
		}
	}

	int __T__; rd(__T__);
	for (int xx = 1; xx <= __T__; xx++) {
		printf("Case #%d:\n", xx);
		_solve_();
	}
	return 0;
}