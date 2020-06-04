#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
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
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int comp[MAXN];
vector<int> divi[MAXN];
int a[MAXN];
int ans[MAXN];

inline void _solve_(int __ntest__) {
	int n; rd(n);
	for (int i = 1; i <= n; i++) rd(a[i]);

	int ret = 0;
	for (int i = 1; i <= n; i++) {
		ans[i] = 1;

		for (int j : divi[i]) {
			if (a[i] > a[j]) {
				ans[i] = max(ans[i], ans[j]+1);
			}
		}
		ret = max(ret, ans[i]);
	}

	printf("%d\n", ret);
}

int main() {

	for (int i = 1; i <= 1e5; i++) {
		if (!comp[i]) {
			for (int j = i + i; j <= 1e5; j += i) {
				divi[j].eb(i);
				if (i != 1) comp[j] = false;
			}
		}
	}


	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}