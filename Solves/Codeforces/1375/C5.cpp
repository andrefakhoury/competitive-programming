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

int n;

vector<int> go(vector<int> a, int i) {
	printf(">>%d\n", i);
	for (int i : a) printf("%d ", i);
	printf("\n");
	a.erase(a.begin()+i);
	for (int i : a) printf("%d ", i);
	printf("\n");
	return a;
}

bool solve(vector<int> a) {
	if (a.size() == 1) return true;

	for (int i = 1; i < n; i++) {
		if (a[i-1] < a[i] && (solve(go(a, i-1)) or solve(go(a, i)))) {
			return true;
		}
	}
	
	return false;

}

inline void _solve_(int __ntest__) {
	rd(n);
	vector<int> a(n);
	for (int& i : a) rd(i);
	bool ans = solve(a);
	printf("%s\n", ans ? "YES" : "NO");
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}