#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) {cout.flush(); fflush(stdout); fprintf(stderr, args);}
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

template<int const MOD1, int const MOD2>
struct Modint {
	int val1, val2;

	Modint() : val1(), val2() {}
	Modint(int v1, int v2) : val1(v1), val2(v2) {}
	Modint(int v) : val1(v), val2(v) {}
	Modint(ll v1, ll v2) : val1(v1), val2(v2) {}
	Modint(ll v) : val1(v), val2(v) {}

	inline Modint operator+(Modint const& rhs) {
		Modint y = {val1 + rhs.val1, val2 + rhs.val2};
		if (y.val1 >= MOD1) y.val1 -= MOD1;
		if (y.val2 >= MOD2) y.val2 -= MOD2;
		return y;
	}

	inline Modint operator*(Modint const& rhs) {
		return {ll(val1) * rhs.val1 % MOD1, ll(val2) * rhs.val2 % MOD2};
	}

	inline bool operator==(Modint const& rhs) {
		return tie(val1, val2) == tie(rhs.val1, rhs.val2);
	}
};

using mint = Modint<1000000007, 1000000009>;

int main() {
	cin.tie(NULL)->sync_with_stdio(false);
	string s; cin >> s;
	int n = s.size();

	mint N, p10 = 1;
	for (int i = n-1; ~i; i--) {
		N = N + p10 * int(s[i] - '0');
		p10 = p10 * 10;
	}

	mint f0 = 0, f1 = 1, f2;

	bool ans = false;
	for (int i = 2; !ans && i <= 1e7; i++) {
		ans |= f0 == N or f1 == N;
		f2 = f0 + f1;
		f0 = f1;
		f1 = f2;
	}

	cout << (ans ? "SIM" : "NAO") << '\n';
}