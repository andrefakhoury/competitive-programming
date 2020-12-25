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

	if (n < 3) {
		puts("0");
		for (int i : a) printf("%d ", i);
		puts("");
		return 0;
	}

	vector<int> cur = {2, 1, 3};
	for (int i = 4; i <= n; i++) {
		if (i%2 == 0) cur.pb(i);
		else {
			int s1 = cur.back(); cur.pop_back();
			int s2 = cur.back(); cur.pop_back();
			cur.pb(i);
			cur.pb(s2);
			cur.pb(s1);
		}
	}

	int ans = 0;
	for (int i = 1; i+1 < n; i++) {
		ans += cur[i] < cur[i-1] && cur[i] < cur[i+1];
	}

	printf("%d\n", ans);
	for (int i : cur) printf("%d ", a[i-1]);
	puts("");
}
