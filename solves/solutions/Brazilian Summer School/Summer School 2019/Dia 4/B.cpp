#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
const int COORDS = 1000001;

struct point {
	int x, y;
	point() {}
	point(int a, int b) {
		x = a;
		y = b;
	}
};

point sumPoints(point q, point p) {
	return point(q.x + p.x, q.y + p.y);
}
point subPoints(point q, point p) {
	return point((q.x - p.x), (q.y - p.y));
}

struct wall {
	point p, q;
	wall() {}
	wall(point a, point b) {
		p = a, q = b;
	}
};

long long cross(point p, point q) {
	return (p.x*q.y - p.y*q.x);
}

bool inter(point a, point b, point c, point d) {
	ll a1 = cross(subPoints(d, a), subPoints(b, a));
	ll a2 = cross(subPoints(c, a), subPoints(b, a));
	ll a3 = cross(subPoints(a, c), subPoints(d, c));
	ll a4 = cross(subPoints(b, c), subPoints(d, c));

	if ((a1 > 0 && a2 > 0) || (a1 < 0 && a2 < 0)) return false;
	if ((a3 > 0 && a4 > 0) || (a3 < 0 && a4 < 0)) return false;
	return true;
}

vector<point> kids;
vector<wall> walls;

bool cmpWallX(wall& a, wall& b) {
	return min(a.p.x, a.q.x) < min(b.p.x, b.q.x);
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	int s, k, w;
	while(~scanf("%d%d%d", &s, &k, &w)) {
		int x, y, x1, y1;
		for (int i = 0; i < s; i++) {
			scanf("%d%d", &x, &y);
			kids.pb(point(x, y));
		}
		for (int i = s; i < k; i++) {
			scanf("%d%d", &x, &y);
			kids.pb(point(x, y));
		}
		for (int i = 0; i < w; i++) {
			scanf("%d%d", &x, &y);
			scanf("%d%d", &x1, &y1);
			walls.pb(wall(point(x, y), point(x1, y1)));
		}

		sort(walls.begin(), walls.end(), cmpWallX);
		for (int i = 0; i < s; i++) {
			int ans = 0;
			for (int j = 0; j < k; j++) {
				if (i == j) continue;
				bool col = false;
				for (int wa = 0; wa < w; wa++) {
					if (inter(kids[i], kids[j], walls[wa].p, walls[wa].q) or
						inter(kids[j], kids[i], walls[wa].p, walls[wa].q) or
						inter(kids[i], kids[j], walls[wa].q, walls[wa].p) or
						inter(kids[j], kids[i], walls[wa].q, walls[wa].p)) {
						col = true;
						break;
					}
				}
				ans += col ? 0 : 1;						
			}
			printf("%d\n", ans);
		}

		kids.clear();
		walls.clear();
	}

	return 0;
}
