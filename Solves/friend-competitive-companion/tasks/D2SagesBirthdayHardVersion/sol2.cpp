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

	multiset<int> ms;
	map<int, int> f;
	for (int i = 0; i < n; i++) ms.insert(-a[i]), f[-a[i]]++;

	vector<int> v;
	auto go = [&](int x) {
		v.eb(-x);
		f[x]--;
		ms.erase(ms.find(x));
	};

	for (int i = 0; i < n; i++) {
		if (i%2 == 0) {
			go(*ms.begin());
		} else {
			auto it = ms.upper_bound(*ms.begin());
			if (it == ms.end() || f[*ms.rbegin()] >= f[*it]) {
				go(*ms.rbegin());
			} else go(*it);
		}
	}

	int ans = 0;
	for (int i = 1; i+1 < n; i++) {
		ans += v[i] < v[i-1] && v[i] < v[i+1];
	}

	printf("%d\n", ans);
	for (int i : v) printf("%d ", i);
	puts("");
}
