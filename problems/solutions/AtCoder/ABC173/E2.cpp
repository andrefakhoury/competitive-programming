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

const ll MAXN = 2e5 + 5, INF = 0x3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;

ll solve(vector<int> const& a, int i, int k, ll cur = 1) {
	if (k == 0) return cur;
	if (i < 0) return -INF;

	return max(solve(a, i-1, k, cur), solve(a, i-1, k-1, cur * a[i]));
}

int main() {
	int n, k; rd(n, k);
	vector<int> a(n);
	for (int& i : a) rd(i);

	printf("%lld\n", (solve(a, n-1, k) % MOD + MOD) % MOD);
}