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

const int MAXN = 2e3 + 5, INF = 0x3f3f3f3f;

struct TwoSat {
	vector<int> edges[MAXN];
	vector<int> reved[MAXN];

	inline int getPos(int i) { return i + i; }
	inline int getNeg(int i) { return i + i + 1; }
	inline void addEdge(int u, int v) {
		edges[u].push_back(v);
		reved[v].push_back(u);
	}

	void dfsOrder(int u, vector<int>& vis, vector<int>& order) {
		vis[u] = 1;
		for (int v : edges[u]) if (!vis[v])
			dfsOrder(v, vis, order);
		order.pb(u);
	}
	void dfsSCC(int u, int c, vector<int>& comp) {
		comp[u] = c;
		for (int v : reved[u]) if (!comp[v])
			dfsSCC(v, c, comp);
	}

	/** verify satisfiability. N is the number of VARIABLES on graph (qttVertices / 2) */
	inline bool isSat(int n, vector<int>& states) {
		states.assign(n, -1);
		vector<int> color(n + n);
		vector<int> order;
		for (int i = 0; i < n + n; i++) if (!color[i])
			dfsOrder(i, color, order);
		reverse(order.begin(), order.end());
		fill(color.begin(), color.end(), 0);
		for (int i = 0, c = 0; i < n + n; i++) if (!color[order[i]])
			dfsSCC(order[i], ++c, color);
		for (int i = 0; i < n + n; i += 2) {
			if (color[i] == color[i+1])
				return false;
		}
		for (int i = n + n - 1; i >= 0; i--) {
			if (states[order[i] / 2] == -1)
				states[order[i] / 2] = !(order[i]&1);
		}
		return true;
	}
};

struct Point {
	ll x, y;
	inline void read() {
		scanf("%lld%lld", &x, &y);
	}
	Point operator-(Point const& p) const{
		return {x-p.x, y-p.y};
	}
	ll operator*(Point const& p) const {
		return x*p.x+y*p.y;
	}
	ll operator^(Point const& p) const {
		return x*p.y-y*p.x;
	}
	bool operator<(Point const& p) const {
		return mk(x, -y) < mk(p.x, -p.y);
	}
};

struct Rect {
	Point p[4];
	/*     p0   p2
	 *     p1   p3     */

	inline void read() {
		for (int i = 0; i < 4; i++)
			p[i].read();
		sort(p, p+4);
	}
};

double norm(double x) {
	if(x > 0)   return 1;
	if(x < 0)   return -1;
	return 0;
}

double sig_mul(double a, double b) {
	a = norm(a);
	b = norm(b);
	return a*b;
}

bool inter (const Point &a, const Point &b, const Point &c, const Point &d) {
	Point ab = b-a;
	Point ac = c-a;
	Point ad = d-a;

	Point cd = d-c;
	Point ca = a-c;
	Point cb = b-c;

	// a, b, c, d -> Colineares
	// Se estiver desconsiderando endpoints nao precisa, essa parte +- testada
	if(abs(ab^ac) == 0 and abs(ab^ad) == 0) {
		Point bc = c-b;
		Point bd = d-b;
		Point da = a-d;
		Point db = b-d;
		if((ac*ad) <= 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
			return true;
		if((bc*bd) <= 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
			return true;
		if((ca*cb) <= 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
			return true;
		if((da*db) <= 0.0)  // < para descosiderar endpoints(soh igual a zero quando c=d)
			return true;
		return false;
	}

	// >= para desconsiderar endpoints
	if(sig_mul(ab^ac, ab^ad) > 0.0)
		return false;

	// >= para desconsiderar endpoints
	if(sig_mul(cd^ca, cd^cb) > 0.0)
		return false;

	return true;
}


bool collision(Point p1, Point p2, Point q1, Point q2) {
	return inter(p1, p2, q1, q2);
}

int main() {
	int n;
	while(scanf("%d", &n), n) {
		vector<Rect> a(n);
		for (int i = 0; i < n; i++) a[i].read();

		TwoSat g;
		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if (collision(a[i].p[0], a[i].p[3], a[j].p[0], a[j].p[3])) {
//					printf("Collision(1,1) [%d %d] -> [%lld,%lld %lld,%lld], [%lld,%lld %lld,%lld]\n", i, j, a[i].p[0].x, a[i].p[0].y, a[i].p[3].x, a[i].p[3].y, a[j].p[0].x, a[j].p[0].y, a[j].p[3].x, a[j].p[3].y);
					g.addEdge(g.getPos(i), g.getNeg(j));
					g.addEdge(g.getPos(j), g.getNeg(i));
				}

				if (collision(a[i].p[0], a[i].p[3], a[j].p[1], a[j].p[2])) {
//					printf("Collision(1,0) [%d %d] -> [%lld,%lld %lld,%lld], [%lld,%lld %lld,%lld]\n", i, j, a[i].p[0].x, a[i].p[0].y, a[i].p[3].x, a[i].p[3].y, a[j].p[1].x, a[j].p[1].y, a[j].p[2].x, a[j].p[2].y);
					g.addEdge(g.getPos(i), g.getPos(j));
					g.addEdge(g.getNeg(j), g.getNeg(i));
				}

				if (collision(a[i].p[1], a[i].p[2], a[j].p[1], a[j].p[2])) {
//					printf("Collision(0,0) [%d %d] -> [%lld,%lld %lld,%lld], [%lld,%lld %lld,%lld]\n", i, j, a[i].p[0].x, a[i].p[0].y, a[i].p[3].x, a[i].p[3].y, a[j].p[0].x, a[j].p[0].y, a[j].p[3].x, a[j].p[3].y);
					g.addEdge(g.getNeg(i), g.getPos(j));
					g.addEdge(g.getNeg(j), g.getPos(i));
				}

				if (collision(a[i].p[1], a[i].p[2], a[j].p[0], a[j].p[3])) {
//					printf("Collision(0,1) [%d %d] -> [%lld,%lld %lld,%lld], [%lld,%lld %lld,%lld]\n", i, j, a[i].p[1].x, a[i].p[1].y, a[i].p[2].x, a[i].p[2].y, a[j].p[1].x, a[j].p[1].y, a[j].p[2].x, a[j].p[2].y);
					g.addEdge(g.getNeg(i), g.getNeg(j));
					g.addEdge(g.getPos(j), g.getPos(i));
				}
			}
		}

		vector<int> states;
		printf("%s\n", g.isSat(n, states) ? "YES" : "NO");
//		for (int i : states) printf("%d ", i);
//		puts("");
	}
}