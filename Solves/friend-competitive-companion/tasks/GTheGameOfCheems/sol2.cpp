#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl 
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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Hash {
	static constexpr int MOD[2] = {(int) 1e9+7, (int) 1e9+9};
	int val[2];

	Hash() { val[0] = val[1] = 0; }
	Hash(string const& s) { *this = calculateHash(s); }
	Hash(int x) { val[0] = x % MOD[0]; val[1] = x % MOD[1]; }
	Hash(int x, int y) { val[0] = x % MOD[0]; val[1] = y % MOD[1]; }

	static int add(int x, int y, int k) { x += y; if (x >= MOD[k]) x -= MOD[k]; return x; }
	static int sub(int x, int y, int k) { x -= y; if (x < 0) x += MOD[k]; return x; }
	static int mul(int x, int y, int k) { return 1ll * x * y % MOD[k]; }
	static int fpow(int x, int y, int k) {
		int r = 1;
		for (; y > 0; y /= 2, x = mul(x, x, k))
			if (y % 2 == 1) r = mul(r, x, k);
		return r;
	}
	static int divi(int x, int y, int k) { return mul(x, fpow(y, MOD[k] - 2, k), k); }
	static Hash pow(Hash x, int y) {
		Hash r = 1;
		for (; y >= 0; y /= 2, x *= x)
			if (y%2 == 1) r *= x;
		return r;
	}

	Hash operator+(Hash const& h) const { return Hash(add(val[0], h.val[0], 0), add(val[1], h.val[1], 1)); }
	Hash operator-(Hash const& h) const { return Hash(sub(val[0], h.val[0], 0), sub(val[1], h.val[1], 1)); }
	Hash operator*(Hash const& h) const { return Hash(mul(val[0], h.val[0], 0), mul(val[1], h.val[1], 1)); }
	Hash operator/(Hash const& h) const { return Hash(divi(val[0], h.val[0], 0), divi(val[1], h.val[1], 1)); }
	Hash& operator+=(Hash const& h) { return *this = *this + h; }
	Hash& operator-=(Hash const& h) { return *this = *this - h; }
	Hash& operator*=(Hash const& h) { return *this = *this * h; }
	Hash& operator/=(Hash const& h) { return *this = *this / h; }

	bool operator==(Hash const& h) const { return val[0] == h.val[0] && val[1] == h.val[1]; }
	bool operator<(Hash const& h) const { return pii(val[0], val[1]) < pii(h.val[0], h.val[1]); }
	bool operator!=(Hash const& h) const { return val[0] != h.val[0] || val[1] != h.val[1]; }

	static Hash calculateHash(string const& s, Hash const primes = Hash(31, 37)) {
		Hash cur = 0;
		Hash p = 1;
		for (char c : s) {
			cur += p * (c - 'a' + 1); // assuming that is a lowercase string
			p *= primes;
		}
		return cur;
	}
	static vector<Hash> calculateHashVector(string const& s, Hash const primes = Hash(31, 37)) {
		int n = s.size();
		Hash p = 1;
		vector<Hash> cur(n);
		for (int i = 0; i < n; i++) {
			if (i) cur[i] = cur[i-1];
			cur[i] += p * (s[i] - 'a' + 1);
			p *= primes;
		}
		return cur;
	}
	static vector<Hash> calculatePowerVector(Hash p, const int n) {
		vector<Hash> ans(n);
		ans[0] = 1;
		for (int i = 1; i < n; i++)
			ans[i] = ans[i-1] * p;
		return ans;
	}
};

ostream& operator<<(ostream& out, Hash const& h) {
	return out << "[" << h.val[0] << "," << h.val[1] << "]";
}

#define hash UISHDUIAHSDU

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, k; cin >> n >> k;
	string s; cin >> s;





}
