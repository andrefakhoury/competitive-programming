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

struct cosa {
	int tipo; // >, >=, < --> 1 2 3
	int l, r;

	cosa() {}
	cosa(int a, int b, int c) : tipo(a), l(b), r(c) {}
};

inline void _solve_(int __ntest__) {
	int n, k; rd(n, k);

	bool ans = false;
	bool can1 = false;
	bool has1 = false;

	vector<cosa> a;
	int last2 = -100;
	int last1 = -100;

	for (int i = 1; i <= n; i++) {
		int X; rd(X);

		if (n == 1 && X == k) ans = true;

		if (X == k) {
			has1 = true;
			if (a.size() && a.back().tipo <= 2) {
				a.back().tipo = 2;
				a.back().r = i;
			} else {
				a.eb(2, i, i);
			}
		} else if (X < k) {
			if (a.size() && a.back().tipo == 3) {
				a.back().r = i;
			} else {
				a.eb(3, i, i);
			}
		} else if (X > k) {
			if (a.size() && a.back().tipo <= 2) {
				a.back().r = i;
			} else {
				a.eb(1, i, i);
			}
		}

		if (a.back().tipo == 2) {
			if (i - last2 + 1 <= 3 or a.back().r - a.back().l + 1 >= 2) ans = true;
			last2 = i;
		}

		if (a.back().tipo <= 2) {
			if (i - last1 + 1 <= 3 or a.back().r - a.back().l + 1 >= 2) can1 = true;
			last1 = i;
		}
	}

	printf("%s\n", (ans or (has1 && can1)) ? "yes" : "no");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}