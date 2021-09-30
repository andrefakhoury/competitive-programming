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
using ii = pair<int, int>;

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

int const maxn = 101010;

int cnt[maxn];

void add(int p) {
	cnt[p]++;

	for (int i = p; cnt[i] == 2 and i < maxn; i++) {
		cnt[i+1]++;
		cnt[i] = 0;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;

		add(x);
	}

	int c = count(all(cnt), 1);

	bool ok = (n > 1) and (c <= 2);

	if (ok) cout << "Y\n";
	else cout << "N\n";
}

