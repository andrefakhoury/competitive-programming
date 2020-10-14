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
#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }
template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Hash {
	static constexpr int MOD[2] = {(int) 1e9+7, (int) 1e9+9};
	int val[2];

	Hash() {}
	Hash(int x) { val[0] = x % MOD[0]; val[1] = x % MOD[1]; }
	Hash(int x, int y) { val[0] = x % MOD[0]; val[1] = y % MOD[1]; }

	int add(int x, int y, int k) const { x += y; if (x >= MOD[k]) x -= MOD[k]; return x; }
	int sub(int x, int y, int k) const { x -= y; if (x < 0) x += MOD[k]; return x; }
	int mul(int x, int y, int k) const { return 1ll * x * y % MOD[k]; }

	Hash operator+(Hash const& h) const { return Hash(add(val[0], h.val[0], 0), add(val[1], h.val[1], 1)); }
	Hash operator-(Hash const& h) const { return Hash(sub(val[0], h.val[0], 0), sub(val[1], h.val[1], 1)); }
	Hash operator*(Hash const& h) const { return Hash(mul(val[0], h.val[0], 0), mul(val[1], h.val[1], 1)); }
	Hash& operator+=(Hash const& h) { return *this = *this + h; }
	Hash& operator*=(Hash const& h) { return *this = *this * h; }
	Hash& operator-=(Hash const& h) { return *this = *this - h; }

	bool operator==(Hash const& h) const { return val[0] == h.val[0] && val[1] == h.val[1]; }
	bool operator!=(Hash const& h) const { return val[0] != h.val[0] || val[1] != h.val[1]; }
};

vector<int> divisors(string const& s) { // return vector of indices i s.t. s[0..i] divides s
	int n = s.size();

	Hash primes(31, 37);

	vector<Hash> curPrime(n + 1);
	curPrime[0] = 1;
	for (int i = 1; i <= n; i++) curPrime[i] = curPrime[i-1] * primes;

	Hash total = 0;
	for (int i = 0; i < n; i++) total += curPrime[i] * (s[i] - 'a' + 1);

	vector<int> ans;
	for (int sz = 1; sz <= n; sz++) if (n % sz == 0) {
		Hash curHash = 0;
		for (int i = 0; i < sz; i++) curHash += curPrime[i] * (s[i] - 'a' + 1);
		Hash finalHash = 0;
		for (int i = 0; i < n; i += sz) finalHash += curHash * curPrime[i];
		if (finalHash == total) ans.pb(sz - 1);
	}

	return ans;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string a, b; cin >> a >> b;

	auto v1 = divisors(a);
	auto v2 = divisors(b);

	int ans = 0;
	for (int i = 0; i < (int) min(a.size(), b.size()); i++) {
		if (a[i] != b[i]) break;
		ans += binary_search(v1.begin(), v1.end(), i) && binary_search(v2.begin(), v2.end(), i);
	}

	cout << ans << "\n";
}