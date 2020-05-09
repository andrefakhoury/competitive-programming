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
} template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 3000 + 5, INF = 0x3f3f3f3f;

template<int const MOD>
struct Modint {
	int val;
	
	Modint() : val() {}
	Modint(int val) : val(val) {}
	Modint(ll val) : val(val) {}
	Modint(char val) : val(val) {}

	inline Modint operator*(Modint const& rhs) { return ll(val) * rhs.val % MOD; }
	inline Modint operator+(Modint const& rhs) { return val + rhs.val >= MOD ? val + rhs.val - MOD : val + rhs.val; }
	inline Modint& operator+=(Modint const& rhs) { return *this = (*this) + rhs; }
	inline Modint& operator*=(Modint const& rhs) { return *this = (*this) * rhs; }
	inline bool operator==(Modint const& rhs) { return val == rhs.val; }

	inline Modint fastPow(int y) {
		Modint ret = 1;
		Modint x = val;
		while(y) {
			if (y&1) ret *= x;
			x *= x;
			y /= 2;
		}
		return ret;
	}

	inline Modint inv() {
		return fastPow(MOD-2);
	}
}; template<int const MOD> ostream& operator<<(ostream& os, Modint<MOD> const& m) { return os << m.val; }

using mint = Modint<998244353>;

mint qtt[MAXN][MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s, t; cin >> s >> t;
	int n = s.size(), m = t.size();

	for (int i = 0; i < (int) s.size(); i++) {
		// se eu colocar no comeco
		mint ini, fim;

		for (int j = 0; j < (int) t.size(); j++) {
			if (t[j] == s[i]) {
				ini = ini + qtt[j][]

			}
		}

	}

	cout << ans.val << "\n";

}