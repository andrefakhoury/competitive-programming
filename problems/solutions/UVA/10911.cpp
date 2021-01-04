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

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

struct Point {
	int x, y;
	inline void read() {
		scanf(" %*s%d%d", &x, &y);
	}

	inline double dist(Point const& p) {
		return hypot(x-p.x, y-p.y);
	}
} st[16];

double memo[1 << 16];

double solve(int mask, int n) {
	if (mask+1 == (1 << n)) return 0;
	double& ret = memo[mask];
	if (ret) return ret;

	ret = 1e7;
	for (int i = 0; i < n; i++) {
		if (mask&(1 << i)) continue;

		for (int j = i+1; j < n; j++) {
			if (mask&(1<<j)) continue;

			int nmask = mask | (1 << i) | (1 << j);
			ret = min(ret, st[i].dist(st[j]) + solve(nmask, n));
		}

		break;
	}

	return ret;
}

inline double isolve(int n) {
	for (int i = 0; i < n; i++) st[i].read();
	mset(memo, 0);
	return solve(0, n);
}

int main() {
	int n, cs = 0;
	while(scanf("%d", &n), n) {
		printf("Case %d: %.2lf\n", ++cs, isolve(n+n));
	}
}