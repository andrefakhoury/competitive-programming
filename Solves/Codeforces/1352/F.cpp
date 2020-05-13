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

const int MAXN = 100 + 5, INF = 0x3f3f3f3f;

struct Stt {
	int w, a, b, c;
};

int memo[2][MAXN][MAXN][MAXN];
Stt nxt[2][MAXN][MAXN][MAXN];

bool solve(int who, int a, int b, int c) {
	if (a < 0 or b < 0 or c < 0) {
		return false;
	}

	int& ret = memo[who][a][b][c];
	Stt& nx0 = nxt[who][a][b][c];

	if (a == 0 && b == 0 && c == 0) {
		nx0 = {-1, -1, -1, -1};
		return true;
	}

	if (~ret) return ret;

	if (who == 0) {
		if (solve(0, a-1, b, c)) {
			nx0 = {0, a-1, b, c};
			return true;
		} else if (solve(1, a, b-1, c)) {
			nx0 = {1, a, b-1, c};
			return true;
		}
	} else {
		if (solve(0, a, b-1, c)) {
			nx0 = {0, a, b-1, c};
			return true;
		} else if (solve(1, a, b, c-1)) {
			nx0 = {1, a, b, c-1};
			return true;
		}
	}

	return false;
}

inline void _solve_(int __ntest__) {
	int a, b, c; rd(a, b, c);

	for (int z = 0; z < 2; z++) {
		for (int i = 0; i <= a; i++) {
			for (int j = 0; j <= b; j++) {
				for (int k = 0; k <= c; k++) {
					memo[z][i][j][k] = -1;
				}
			}
		}
	}

	if (solve(1, a, b, c)) {
		Stt cur = {1, a, b, c};
		while(cur.w != -1) {
			printf("%d", cur.w);
			cur = nxt[cur.w][cur.a][cur.b][cur.c];
		}
	} else if (solve(0, a, b, c)) {
		Stt cur = {0, a, b, c};
		while(cur.w != -1) {
			printf("%d", cur.w);
			cur = nxt[cur.w][cur.a][cur.b][cur.c];
		}
	} else {
		assert(0);
	}
	printf("\n");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}