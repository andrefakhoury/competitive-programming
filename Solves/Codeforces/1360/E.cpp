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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	int n; cin >> n;
	vector<string> a(n);
	for (string& s : a) cin >> s;

	vector<string> b(n, string(n, '0'));

	auto has = [&](int i, int j) {
		return i < 0 or j < 0 or i >= n or j >= n or b[i][j] == '1';
	};	

	for (int j = n-1; j >= 0; j--) { // each col
		for (int i = n-1; i >= 0; i--) {
			if (a[i][j] == '1') { // has TO SHOOT!
				if (has(i, j+1) or has(i+1, j)) {
					b[i][j] = '1';
				} else {
					puts("NO");
					return;
				}
			}
		}
	}

	puts("YES");
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}