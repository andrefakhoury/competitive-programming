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

const int MAXN = 1e4 + 5, INF = 0x3f3f3f3f;

/* -=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=- *
 *                                          -- begin of Geometry notebook --                                          *
 * -=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=--=- */

/**
 * 2-Dimensional Point
 * @tparam T type of coordinates
 */
template <typename T>
class Point {
public:
	T x, y;

	static constexpr double EPS = 1e-9;

	Point() : x{}, y{} {}
	Point(T x, T y) : x{x}, y{y} {}

	template<typename Ty> Point(Ty x, Ty y) { this->x = static_cast<T>(x); this->y = static_cast<T>(y); }
	template<typename Tp> inline Point<T>& operator=(Point<Tp> const& rhs) const { return *this = Point<T>(rhs); }
	template<typename Ty> inline Point<T> operator-(Point<Ty> const& rhs) const { return Point<T>(x - rhs.x, y - rhs.y); }
	template<typename Ty> inline Point<T> operator+(Point<Ty> const& rhs) const { return Point<T>(x + rhs.x, y + rhs.y); }
	template<typename Tp> inline Point<T> operator/(Tp const& k) const { return Point<T>(x/k, y/k); }
	template<typename Tp> inline Point<T> operator*(Tp const& k) const { return Point<T>(x*k, y*k); }
	template<typename Ty> inline Point<T>& operator+=(Point<Ty> const& rhs) { return *this = *this + rhs; }
	template<typename Ty> inline Point<T>& operator-=(Point<Ty> const& rhs) { return *this = *this - rhs; }
	template<typename Tp> inline Point<T>& operator/=(Tp const& rhs) { return *this = *this / rhs; }
	template<typename Tp> inline Point<T>& operator*=(Tp const& rhs) { return *this = *this * rhs; }
	template<typename Tp> inline T operator^(Point<Tp> const& rhs) const { return x * rhs.y - y * rhs.x; }
	template<typename Tp> inline T operator*(Point<Tp> const& rhs) const { return x * rhs.x + y * rhs.y; }

	// May cause some precision issues. Check when abs(x - rhs.x) < EPS if necessary.
	inline bool operator<(Point const& rhs) const { return make_pair(x, y) < make_pair(rhs.x, rhs.y); }

	// convex hull without collinear points
	inline static vector<Point<T>> convexHull(vector<Point<T>> p) {
		if (p.size() <= 2u) return p;

		int n = p.size(), k = 0;
		vector<Point<T>> H(2*n);

		sort(p.begin(), p.end());

		for (int i = 0; i < n; i++) {
			while (k >= 2 && ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= T{}) k--;
			H[k++] = p[i];
		}

		for (int i = n-2, t = k+1; i >= 0; i--) {
			while (k >= t && ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= T{}) k--;
			H[k++] = p[i];
		}

		H.resize(k-1);
		return H;
	}

	inline static ll polygonArea(vector<Point<T>> const& a) {
		ll area = 0;
		int n = a.size();

		int j = n-1;
		for (int i = 0; i < n; i++) {
			area += (a[j].x + a[i].x) * (a[j].y - a[i].y);
			j = i;
		}

		return abs(area);
	}
};

template<typename T> ostream& operator<<(ostream& out, Point<T> const& p) { return out << p.x << " " << p.y; }
template<typename T> istream& operator>>(istream& in, Point<T>& p) { return in >> p.x >> p.y; }

using pt = Point<ll>;

struct P3D {
	ll x, y, z;
	ll dist(P3D p) {
		ll dx = x - p.x;
		ll dy = y - p.y;
		ll dz = z - p.z;
		return dx*dx+dy*dy+dz*dz;
	}
};

struct Doge {
	int pillar;
	ll power;
};

struct UF {
	int par[MAXN];
	int sz[MAXN];
	inline void init(int n) {
		iota(par, par+n+1, 0);
		fill(sz, sz+n+1, 1);
	}
	int find(int x) {
		return par[x] == x ? x : par[x] = find(par[x]);
	}
	inline void merge(int u, int v) {
		u = find(u), v = find(v);
		if (sz[u] > sz[v]) swap(u, v);
		if (u != v) par[u] = v, sz[v] += sz[u];
	}
} uf;

vector<pair<int, ll>> edges[MAXN];

bool is_end[MAXN];
ll dist[MAXN];
ll damage[MAXN];

ll dijkstra(int s, int n, ll health) {
	ll MX = health + 1;

	priority_queue<pair<ll, int>> pq;
	for (int i = 0; i <= n; i++) dist[i] = MX;
	dist[s] = 0;
	pq.emplace(0, s);
	while(pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (-d > dist[u]) continue;
		for (auto [v, w] : edges[u]) {
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				dist[v] = min(dist[v], MX);
				pq.emplace(-dist[v], v);
			}
		}
	}

	ll ans = 2 * health + 1;
	for (int i = 0; i < n; i++) if (is_end[i])
		ans = min(ans, dist[i]);
	return ans;
}

int main() {
	int n_pillars; rd(n_pillars);
	vector<P3D> pillars(n_pillars);
	for (int i = 0; i < n_pillars; i++) rd(pillars[i].x, pillars[i].y, pillars[i].z);

	int n_doges; rd(n_doges);
	vector<Doge> doges(n_doges);
	for (int i = 0; i < n_doges; i++) rd(doges[i].pillar, doges[i].power), doges[i].pillar--, doges[i].power *= doges[i].power;

	int n_exits; rd(n_exits);
	vector<int> exits(n_exits);
	for (int i = 0; i < n_exits; i++) rd(exits[i]), exits[i]--, is_end[exits[i]] = true;

	int location;
	ll health, r;
	rd(location, r, health), location--, r *= r;

	uf.init(n_pillars);
	for (int i = 0; i < n_doges; i++)
		for (int j = 0; j < n_doges; j++)
			if (pillars[doges[i].pillar].dist(pillars[doges[j].pillar]) <= doges[i].power)
				uf.merge(doges[i].pillar, doges[j].pillar);

	{ // builds the convex hulls
		vector<int> vis(n_pillars);
		for (int i = 0; i < n_pillars; i++) if (!vis[uf.find(i)]) {
				vis[uf.find(i)] = 1;
				vector<pt> points;
				for (int j = 0; j < n_pillars; j++) {
					if (uf.find(i) == uf.find(j)) points.emplace_back(pillars[j].x, pillars[j].y);
				}
				points = pt::convexHull(points);
				ll total = pt::polygonArea(points);

				set<pt> current;
				for (pt pp : points) current.insert(pp);

				for (int j = 0; j < n_pillars; j++) {
					if (uf.find(i) == uf.find(j)) {
						damage[j] = total;
					}
				}
			}
	}

	for (int i = 0; i < n_pillars; i++) {
		for (int j = 0; j < n_pillars; j++) {
			if (pillars[i].dist(pillars[j]) <= r && pillars[i].z >= pillars[j].z) {
				ll w = damage[j] + 2 * (pillars[i].z - pillars[j].z);
				if (w <= 2 * health) edges[i].eb(j, w);
			}
		}
	}

	ll ans = dijkstra(location, n_pillars, 2 * health);
	if (ans > 2 * health) ans = -2;
	else ans = 2 * health - ans;
	printf("%.8lf\n", ans / 2.0);
}