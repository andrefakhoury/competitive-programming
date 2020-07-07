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
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }
template <class... Args> inline void rf(Args&... args) { (cin >> ... >> args); }
template <class... Args> inline void pr(Args&&... args) { (cout << ... << args); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

inline bool ask(int x) {
	cout << x << endl;
	char y; cin >> y;
	if (y == 'E') exit(0);
	return y == 'L';
}

void solve(int lo, int hi) {
	if (lo > hi) return;

	if (hi - lo + 1 <= 4) {
		for (int i = lo; i <= hi; i++) ask(i);
		return;
	}

	int mi = randint(lo+1, hi-1);
	if (ask(lo) or !ask(hi)) {
		if (ask(mi)) solve(lo, mi-1);
		else solve(mi+1, hi);
	}

	int m1 = ask(mi);
	int m2 = ask(mi+1);
	
	if (m1 == m2) {
		if (m1) solve(lo, mi-1);
		else solve(mi+2, hi);
	} else {
		for (int i = lo+1; i <= lo+5; i++) {
			if (ask(i)) {
				if (ask(mi)) solve(lo, mi-1);
				else solve(mi+1, hi);
			}
		}
		for (int i = hi-1; i >= hi-5; i--) {
			if (!ask(i)) {
				if (ask(mi)) solve(lo, mi-1);
				else solve(mi+1, hi);
			}
		}
	}

	if (rng()%2) {
		if (ask(mi)) solve(lo, mi-1);
		else solve(mi+1, hi);
	} else {
		if (!ask(mi)) solve(lo, mi-1);
		else solve(mi+1, hi);
	}
}

int main() {
	int n; cin >> n;
	solve(1, n);
}