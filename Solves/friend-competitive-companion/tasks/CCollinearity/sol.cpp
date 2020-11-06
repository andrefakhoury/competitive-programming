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
	int x, y;
};

int main() {
	int n; rd(n);
	vector<Point> a(n);
	for (int i = 0; i < n; i++) {
		rd(a[i].x, a[i].y);
	}

	bool ans = false;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int z = j + 1; z < n; z++) {
				Point ij = {a[j].x - a[i].x, a[j].y - a[i].y};
				Point iz = {a[z].x - a[i].x, a[z].y - a[i].y};
				if (ij.x * iz.y - ij.y * iz.x == 0)
					ans = true;


			}
		}
	}
	puts(ans ? "Yes" : "No");
}
