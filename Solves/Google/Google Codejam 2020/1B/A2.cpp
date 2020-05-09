#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) { cout.flush(); fflush(stdout); fprintf(stderr, args); }
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	ll x, y; rd(x, y);
	printf("Case #%d: ", __ntest__);
	bool nx = x < 0, ny = y < 0;
	x = abs(x), y = abs(y);

	const int MAXL = 500;

	vector<int> bx(MAXL+5), by(MAXL+5);

	for (int i = 0; i <= 63; i++) {
		bx[i] = (x & (1ll << i)) != 0;
		by[i] = (y & (1ll << i)) != 0;
	}

	auto invt = [&](char c) {
		if (c == 'E') return 'W';
		if (c == 'W') return 'E';
		if (c == 'N') return 'S';
					  return 'N';
	};

	string ans(MAXL+5, '0');
	bool imp = false;

	int cx = 0, cy = 0;
	for (int i = 0; i < MAXL; i++) {
		bx[i] += cx;
		by[i] += cy;

		if (bx[i] > 1) {
			cx = bx[i] - 1;
			bx[i] = 1;
		} else cx = 0;
		if (by[i] > 1) {
			cy = by[i] - 1;
			by[i] = 1;
		} else cy = 0;

		if (bx[i] && by[i]) {
			if (i > 0 && bx[i-1]) bx[i-1] *= -1, cx++, bx[i] = 0;
			else if (i > 0 && by[i-1]) by[i-1] *= -1, cy++, by[i] = 0;
			else imp = true;
		}
	}

	for (int i = 1; i < MAXL; i++) {
		if (!bx[i] && !by[i]) {
			for (int j = i; j < MAXL; j++) {
				if (bx[j] && bx[i-1]) {
					// preciso preencher do i+1 ate o j-1
					bx[i-1] *= -1;
					for (int k = i; k < j-1; k++) bx[k] = bx[k-1];
					bx[j-1] = bx[i-1] * -1;
				} else if (by[j] && by[j-1]) {
					by[i-1] *= -1;
					for (int k = i; k < j-1; k++) by[k] = by[k-1];
					by[j-1] = by[i-1] * -1;
				} else continue;
				i = j;
				break;
			}
		}
	}

	for (int i = 0; i < MAXL; i++) {
		if (bx[i]) {
			ans[i] = !nx ? 'E' : 'W';
			if (bx[i] < 0) ans[i] = invt(ans[i]);
		} else if (by[i]) {
			ans[i] = !ny ? 'N' : 'S';
			if (by[i] < 0) ans[i] = invt(ans[i]);
		} else {
			for (; i < MAXL; i++) {
				for (; i < MAXL; i++) {
					imp |= bx[i] || by[i];
				}
			}
		}
	}

	if (imp) printf("IMPOSSIBLE\n");
	else {
		for (int i = 0; ans[i] != '0'; i++) printf("%c", ans[i]);
		printf("\n");
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}