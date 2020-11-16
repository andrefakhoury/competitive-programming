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
const int N = 21;

int pos[N];
int bt[N];

int main() {
	auto ck = clock();

	int n; rd(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]), pos[a[i]] = 1;

	vector<int> ord;
	for (int i = 0; i < N; i++) if (pos[i]) ord.pb(i);

	ll ans = LLONG_MAX;
	while(double(clock() - ck) / CLOCKS_PER_SEC <= 3.7) {
		shuffle(ord.begin(), ord.end(), rng);
		for (int i = 0; i < (int) ord.size(); i++) pos[ord[i]] = i + 1;
		mset(bt, 0);
		ll cur = 0;
		for (int i = 0; i < n; i++) {
			for (int j = pos[a[i]] - 1; j > 0; j -= j&-j) cur += bt[j];
			for (int j = pos[a[i]]; j < N; j += j&-j) bt[j]++;
		}
		ans = min(ans, cur);
	}

	printf("%lld\n", ans);
}
