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

inline bool isprime(int n) {
	if (n == 1) return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) return false;
	return true;
}

vector<int> solve_small(int n) {
	if (isprime(n)) return {n};
	for (int i = 2; i <= n; i++) {
		if (isprime(i) && isprime(n - i))
			return {i, n - i};
	}

	assert(false);
	return {};
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;

	// k == 1
	if (isprime(n)) cout << 1 << "\n" << n << "\n";
	else {
		for (int i = n; i >= 3; i -= 2) if (isprime(i)) {
			vector<int> x = solve_small(n - i);
			x.pb(i);
			cout << x.size() << "\n";
			for (int y : x) cout << y << ' ';
			cout << '\n';
			return 0;
		}

		assert(false);
	}
}