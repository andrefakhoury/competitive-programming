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

int par[MAXN];
int find(int x) {
	return x == par[x] ? x : par[x] = find(par[x]);
}

void merge(int u, int v) {
	u = find(u), v = find(v);
	par[u] = v;
}

int main() {
	int n; rd(n);
	vector<int> a(n);
	vector<int> all;
	for (int& i : a) rd(i), all.pb(i);
	sort(all.begin(), all.end());
	all.erase(unique(all.begin(), all.end()), all.end());

	for (int i = 0; i < n; i++) a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin();
	for (int i = 0; i < n; i++) par[i] = i;
	for (int i = 0; i < n; i++) merge(i, a[i]);

	map<int, vector<int>> ans;
	for (int i = 0; i < n; i++)
		ans[find(i)].push_back(i);

	printf("%ld\n", ans.size());
	for (auto p : ans) {
		vector<int> v = p.second;
		printf("%ld ", v.size());
		for (int i : v) printf("%d ", i + 1);
		printf("\n");
	}
}