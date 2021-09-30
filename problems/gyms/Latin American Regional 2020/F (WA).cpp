#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) do {cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; } while (0) 

#ifdef _WIN32
#define getchar_unlocked _getchar_nolock
#endif

template<class num> inline void rd(num& x) {
	char c, neg = 0; while(isspace(c = getchar_unlocked()));
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar_unlocked())) x = (x << 3) + (x << 1) + c - '0';
	x = neg ? -x : x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }


using ll = long long;
using ii = pair<ll, ll>;

using Gr = vector<vector<ii>>;

template<typename T = int>
constexpr T inf = 0x3f3f3f3f;

template<>
constexpr ll inf<ll> = 0x3f3f3f3f3f3f3f3f;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rng{seq};
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

int const maxn = 8080;

ll a[maxn];
ll dp[2][maxn];
int now = 0, old = 1;

void trick() {
	swap(now, old);
}

void calc(int k, int n) {
	vector<ii> st;
	multiset<ll> vals; 
	st.emplace_back(0, dp[old][k-1]);
	vals.emplace(dp[old][k-1]);

	for (int i = k; i <= n; i++) {
		ll at = dp[old][i-1];
		while (!st.empty() and st.back().ff <= a[i]) {
			at = min(at, st.back().ss);
			vals.erase(vals.find(st.back().ff + st.back().ss));
			st.pop_back();
		}
		vals.insert(a[i] + at);
		st.emplace_back(a[i], at);

		dp[now][i] = *vals.rbegin();
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	vector<ll> b(n+1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b.begin() + 1, b.end(), greater<ll>{});

	for (int i = 2; i <= n; i++) b[i] += b[i-1];

	for (int i = 1; i <= n; i++) {
		dp[now][i] = max(dp[now][i-1], a[i]);
	}

	vector<ll> rmax(n+1);
	rmax[1] = dp[now][n];

	for (int k = 2; k <= n; k++) {
		trick();
		calc(k, n);
		rmax[k] = dp[now][n];
	}

	for (int i = 1; i <= n; i++) {
		cout << rmax[i] << " " << b[i] << "\n";
	}

}

