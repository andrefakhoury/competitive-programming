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
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Point {
	int x, y, z;
	inline bool read() {
		rd(x, y, z);
		return x + y + z > 0;
	}

	inline int dist(Point const& p) {
		int dx = x - p.x;
		int dy = y - p.y;
		int dz = z - p.z;
		return dx * dx + dy * dy + dz * dz;
	}
};

int main() {
	vector<Point> v; Point p;
	while(p.read()) v.pb(p);

	int n = v.size();

	map<int, int> ans;
	for (int i = 0; i < n; i++) {
		int closest = INT_MAX;
		for (int j = 0; j < n; j++) if (i != j)
			closest = min(closest, v[i].dist(v[j]));
		ans[floor(1e-8 + sqrt(closest))]++;
	}
	for (int i = 0; i < 10; i++) {
		printf("%4d", ans[i]);
	}
	puts("");
}
