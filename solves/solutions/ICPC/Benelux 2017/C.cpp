#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#pragma GCC optimize("expensive-optimizations")
#pragma GCC target("avx,avx2,sse,sse2,sse3,sse4")

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

const int MAXN = 5e5 + 1, LOG = 19;

ll table[LOG][MAXN];

inline void build(int n) {
	for (int j = 1; (1<<j) <= n; j++) 
		for (int i = 0; i + (1<<j) - 1 < n; i++)
			table[j][i] = gcd(table[j-1][i], table[j-1][i + (1<<(j-1))]);
}

int lg[MAXN];
// [[ gnu::target("abm,bmi") ]]
inline ll query(int l, int r) {
	if (l > r) swap (l, r);
	int tam = r - l + 1;
	// return gcd(table[(31-__builtin_clz(tam))][l], table[(31-__builtin_clz(tam))][r - (1<<(31-__builtin_clz(tam))) + 1]);
	return gcd(table[lg[tam]][l], table[lg[tam]][r - (1<<lg[tam]) + 1]);
}

int main() {
	for (int i = 2; i < MAXN; i++) lg[i] = lg[i/2] + 1;
	ll old;
	int lo, hi, mi;
	int i, j;

	int n; rd(n);
	for (int i = 0; i < n; i++) rd(table[0][i]);
	build(n);

	
	auto nxt = [&]() {
		lo = j, hi = n-1;
		while(lo < hi) {
			mi = (lo + hi + 1) / 2;
			if (query(i, mi) == old) lo = mi;
			else hi = mi - 1;
		}

		return lo + 1;
	};

	vector<unsigned int> alli;
	alli.reserve(n * 31);

	// unordered_set<unsigned int> alli;
	// unordered_set<ll> allj;

	vector<ll> allj;
	allj.reserve(n * 28);

	for (i = 0; i < n; i++) {
		for (j = i; j < n; j = nxt()) {
			old = query(i, j);
			if (old <= UINT_MAX) alli.eb(old);
			else allj.eb(old);
		}
	}

	sort(alli.begin(), alli.end());
	sort(allj.begin(), allj.end());

	printf("%ld\n", (unique(alli.begin(), alli.end()) - alli.begin()) + (unique(allj.begin(), allj.end()) - allj.begin()));
}