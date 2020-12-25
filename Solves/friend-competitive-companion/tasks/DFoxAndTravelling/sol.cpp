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

const int MAXN = 105, INF = 0x3f3f3f3f;
const int MOD = 1e9 + 9;

using bts=bitset<MAXN>;

vector<int> edges[MAXN];
vector<bts> dep[MAXN];

void go(int u, int i, bool taken, bts cur) {
	if ((int) cur.count() == (int) edges[u].size() - 1) dep[u].pb(cur);
	if (i == (int) edges[u].size()) return;
	if (!taken) go(u, i + 1, true, cur);
	cur[edges[u][i]] = 1;
	go(u, i + 1, taken, cur);
}

int main() {
	int n, m; rd(n, m);
	for (int i = 1; i <= m; i++) {
		int u, v; rd(u, v);
		edges[u].pb(v);
		edges[v].pb(u);
	}

	for (int i = 1; i <= n; i++) {
		go(i, 0, false, {});
		if (edges[i].empty()) dep[i].emplace_back();
	}

	puts("1");
	set<int> w;
	for (int i = 1; i <= n; i++) {
		for (auto& v : dep[i])
		{
			if (v.count() == 0) w.insert(i);
		}
	}
	printf("%ld\n", w.size());

	for (int k = 0; k <= n; k++) {

	}






}
