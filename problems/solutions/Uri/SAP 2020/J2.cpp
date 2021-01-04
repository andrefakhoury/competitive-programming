#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")

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
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 1e6;
const int MOD = 1e9 + 7;

inline void add(int& x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
}

int ans[MAXN];
pii a[MAXN];
int X[MAXN];

int main() {
	int n; rd(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].fi, a[i].se);
		X[i] = a[i].se;
	}

	sort(X, X+n);
	sort(a, a+n);
	reverse(a, a+n);

	for (int i = 0; i < n; i++)
		a[i].se = lower_bound(X, X+n, a[i].se) - X;

	set<int> cur_x;
	set<int>::iterator it;
	vector<int> same_height;
	int last_height = -1;

	for (int i = 0; i < n; i++) {
		if (last_height != a[i].fi) {
			for (int x : same_height) cur_x.emplace(x);
			same_height.clear();
		}

		int& aise = a[i].se;
		last_height = a[i].fi;
		same_height.eb(aise);

		if (i == 0) ans[aise] = 1;

		it = cur_x.lower_bound(aise);
		if (it != cur_x.end())
			add(ans[aise], ans[*it]);
		if (it != cur_x.begin())
			add(ans[aise], ans[*(--it)]);
	}

	int tot_ans = 0;
	for (int i = 0; i < n; i++) add(tot_ans, ans[i]);
	printf("%d\n", tot_ans);
}