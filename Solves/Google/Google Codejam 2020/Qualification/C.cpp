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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Act {
	int l, r, id;
};

inline void _solve_(int testCase) {
	cout << "Case #" << testCase << ": ";

	int n; cin >> n;
	vector<Act> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].l >> a[i].r;
		a[i].id = i;
	}

	sort(a.begin(), a.end(), [&](Act const& x, Act const& y) {
		return tie(x.l, x.r) < tie(y.l, y.r);
	});

	string ans;
	ans.resize(n);

	int lc = -1, lj = -1, ok = 1;
	for (int i = 0; i < n; i++) {

		if (a[i].l >= lc) {
			lc = a[i].r;
			ans[a[i].id] = 'C';
		} else if (a[i].l >= lj) {
			lj = a[i].r;
			ans[a[i].id] = 'J';
		} else {
			ok = 0;
			break;
		}
	}

	cout << (!ok ? "IMPOSSIBLE" : ans) << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int __T__; cin >> __T__;
	for (int tt = 1; tt <= __T__; tt++) _solve_(tt);
	return 0;
}