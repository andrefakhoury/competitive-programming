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

int main() {
	int n; rd(n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	sort(a.begin(), a.end());

	map<int, int> f;
	for (int i : a) f[i]++;

	set<pii> st;
	for (int i : a) st.emplace(f[i], -i);

	multiset<int> ms;
	for (int i : a) ms.insert(i);

	// coloco o maior cara
	// coloco o cara de maior frequencia

	vector<int> v;

	auto go_big = [&]() {
		int cur = *ms.rbegin();
		ms.erase(ms.find(cur));
		st.erase(mk(f[cur], -cur));
		f[cur]--;
		return cur;
	};

	auto go_small = [&]() {
		if (st.empty()) {
			return go_big();
		}
		int cur = -st.rbegin()->se;
		st.erase(*st.rbegin());
		ms.erase(ms.find(cur));
		f[cur]--;
		if (f[cur]) st.emplace(f[cur], -cur);
		return cur;
	};


	v.pb(go_big());
	for (int i = 1; i+1 < n; i += 2) {
		int x = go_big();
		int y = go_small();
		v.pb(y);
		v.pb(x);
	}
	if (ms.size()) v.pb(go_big());

	int ans = 0;
	for (int i = 1; i+1 < n; i++) {
		ans += v[i] < v[i-1] && v[i] < v[i+1];
	}

	printf("%d\n", ans);
	for (int i : v) printf("%d ", i);
	puts("");
}
