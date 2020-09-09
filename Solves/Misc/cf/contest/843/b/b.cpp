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

const int MAXN = 5e4 + 5, INF = 0x3f3f3f3f;

pii a[MAXN];

inline pii ask(int u) {
	if (a[u] != a[0]) return a[u];
	printf("? %d\n", u);
	fflush(stdout);
	int x, y; scanf("%d%d", &x, &y);
	a[u] = {x, y};
	if (a[u] == mk(-1, -1))
		exit(0);
	return a[u];
}

inline void guess(int x) {
	printf("! %d\n", x);
	fflush(stdout);
	exit(0);
}

int main() {
	mset(a, -1);

	int n, start, x; scanf("%d%d%d", &n, &start, &x);
	vector<int> index(n);
	iota(index.begin(), index.end(), 1);
	shuffle(index.begin(), index.end(), rng);

	ask(start);
	for (int i = 0; i < min(900, n); i++) ask(index[i]);

	int current = start;
	for (int i = 1; i <= n; i++) if (a[i].fi != -1) {
		if (a[i].fi <= x && a[i].fi > a[current].fi)
			current = i;
	}

	for (int i = current; i != -1; i = a[i].se)
		if (ask(i).fi >= x) guess(a[i].fi);

	guess(-1);
}