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

template<class Ty> Ty rnd(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
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

const int MAXN = 1e6+1, INF = 0x3f3f3f3f;

int bt[MAXN];

inline void update(int i, int k) {
	while(i < MAXN) {
		bt[i] += k;
		i += i&-i;
	}
}

inline int query(int i) {
	int ret = 0;
	while(i) {
		ret += bt[i];
		i -= i&-i;
	}
	return ret;
}

inline int query(int i, int j) {
	return query(j) - query(i-1);
}

int main() {
	int n, q; rd(n, q);

	for (int i = 0; i < n; i++) {
		int x; rd(x);
		update(x, 1);
	}

	auto fkth = [&](int k) {
		int lo = 1, hi = n, mi;
		while(lo < hi) {
			mi = (lo + hi) / 2;
			if (query(1, mi) >= k) hi = mi;
			else lo = mi + 1;
		}
		return hi;
	};

	for (int i = 0; i < q; i++) {
		int x; rd(x);
		if (x > 0) update(x, 1);
		else update(fkth(-x), -1);
	}

	for (int i = 1; i <= n; i++) {
		if (query(i)) {
			printf("%d\n", i);
			return 0;
		}
	}

	puts("0");
}