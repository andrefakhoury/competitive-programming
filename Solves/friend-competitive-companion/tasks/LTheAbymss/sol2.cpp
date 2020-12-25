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

	template<typename Ty> Point(Ty x, Ty y) {
		this->x = static_cast<T>(x);
		this->y = static_cast<T>(y);
	}

	template<typename Tp> inline Point<T>& operator=(Point<Tp> const& rhs) const { return *this = Point<T>(rhs); }

	template<typename Ty> inline Point<T> operator-(Point<Ty> const& rhs) const { return Point<T>(x - rhs.x, y - rhs.y); }
	template<typename Ty> inline Point<T> operator+(Point<Ty> const& rhs) const { return Point<T>(x + rhs.x, y + rhs.y); }
	template<typename Tp> inline Point<T> operator/(Tp const& k) const { return Point<T>(x/k, y/k); }
	template<typename Tp> inline Point<T> operator*(Tp const& k) const { return Point<T>(x*k, y*k); }

	template<typename Ty> inline Point<T>& operator+=(Point<Ty> const& rhs) { return *this = *this + rhs; }
	template<typename Ty> inline Point<T>& operator-=(Point<Ty> const& rhs) { return *this = *this - rhs; }
	template<typename Tp> inline Point<T>& operator/=(Tp const& rhs) { return *this = *this / rhs; }
	template<typename Tp> inline Point<T>& operator*=(Tp const& rhs) { return *this = *this * rhs; }

	template<typename Tp> // cross product
	inline T operator^(Point<Tp> const& rhs) const { return x * rhs.y - y * rhs.x; }

	template<typename Tp> // dot product
	inline T operator*(Point<Tp> const& rhs) const { return x * rhs.x + y * rhs.y; }

	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }

	template <typename Ty>
	inline double dist(Point<Ty> const& p) const { return (*this - p).len(); }

	template <typename Ty>
	inline T dist2(Point<Ty> const& p) const { return (*this - p).len2(); }

	// May cause some precision issues. Check when abs(x - rhs.x) < EPS if necessary.
	inline bool operator<(Point const& rhs) const { return make_pair(x, y) < make_pair(rhs.x, rhs.y); }

	// orthogonal projection
	inline double proj(Point const& b) const { return static_cast<double>((*this)*b) / b.len2(); }

	// -1 if negative, 0 if 0 and 1 if positive
	template <typename Tp>
	inline static char sign(Tp x) { return abs(x) < EPS ? 0 : x < 0 ? -1 : 1; }

	// sign of multiplication a*b
	template <typename Ta, typename Tb>
	inline static char sign_mul(Ta const& a, Tb const& b) { return sign(a) * sign(b); }

	// Orientation of AC relative to AB. 0 = collinear; -1: ccw, 1: cw. NOT TESTED
	inline static char orientation(Point const& a, Point const& b, Point const& c) { return sign((b-a)^(c-a)); }

	// returns whether B lies on 1D segment AC. NOT TESTED
	inline static bool onSegment1D(Point const& a, Point const& b, Point const& c) {
		return b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y);
	}

	// distance of *this to a->b. If needed, the closest point in AB is "Point c", just return it!
	inline double distToSegment(Point const& a, Point const& b) const {
		Point p = *this;
		if ((a - b).len() <= EPS) return (p - a).len();
		Point ap = p - a;
		Point ab = b - a;
		double u = ap.proj(ab);
		u = max(min(u, (double) 1), (double) 0);
		Point c = a + ab * u;
		return (p - c).len();
	}

	// convex hull without collinear points
	inline static vector<Point<T>> convexHull(vector<Point<T>> p) {
		if (p.size() <= 2u) return p;

		int n = p.size(), k = 0;
		vector<Point<T>> H(2*n);

		sort(p.begin(), p.end());

		for (int i = 0; i < n; i++) {
			while (k >= 2 && ((H[k-1]-H[k-2])^(p[i]-H[k-2])) < T{}) k--;
			H[k++] = p[i];
		}

		for (int i = n-2, t = k+1; i >= 0; i--) {
			while (k >= t && ((H[k-1]-H[k-2])^(p[i]-H[k-2])) < T{}) k--;
			H[k++] = p[i];
		}

		H.resize(k-1);
		return H;
	}

	// returns whether (a, b) intersects with (c, d). NOT TESTED
	inline static bool intersect(Point<T> a, Point<T> b, Point<T> c, Point<T> d) {
		if (sign((a-b)^(c-d)) == 0) assert(0);

		char abc = orientation(a, b, c);
		char abd = orientation(a, b, d);
		char cda = orientation(c, d, a);
		char cdb = orientation(c, d, b);
		if (abc != abd && cda != cdb) return true;

		if (abc == 0 && onSegment1D(a, c, b)) return true;
		if (abd == 0 && onSegment1D(a, d, b)) return true;
		if (cda == 0 && onSegment1D(c, a, d)) return true;
		if (cdb == 0 && onSegment1D(c, b, d)) return true;

		return false;
	}

	inline static T maximumDistance2(vector<Point<T>> const& a) { // a is convex, and it's already sorted ccw
		int n = a.size();
		auto next = [&](int i) { return i + 1 == n ? 0 : i + 1; };
		T ans = T(0);
		for (int i = 0, j = n < 2 ? 0 : 1; i < j; ++i) {
			for (;; j = next(j)) {
				ans = max(ans, a[i].dist2(a[j]));
				if (((a[i + 1] - a[i]) ^ (a[next(j)] - a[j])) <= 0) break;
			}
		}
		return ans;
	}

	inline static double polygonArea(vector<Point<T>> const& a) {
		double area = 0.0;
		int n = a.size();

		int j = n-1;
		for (int i = 0; i < n; i++) {
			area += (a[j].x + a[i].x) * (a[j].y - a[i].y);
			j = i;
		}

		return abs(area/2.0);
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
	double area[MAXN];
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

vector<pair<int, double>> edges[MAXN];

bool is_end[MAXN];
double dist[MAXN];
double damage[MAXN];

double dijkstra(int s, int n) {
	priority_queue<pair<double, int>> pq;
	for (int i = 0; i < n; i++) dist[i] = 1e30;
	pq.emplace(0, s);
	dist[s] = 0;
	while(pq.size()) {
		auto [d, u] = pq.top();
		pq.pop();
		if (-d > dist[u]) continue;
		for (auto [v, w] : edges[u]) if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.emplace(-dist[v], v);
			}
	}

	double ans = 1e30;
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

	int location, health;
	ll r;
	rd(location, r, health), location--, r *= r;

	uf.init(n_pillars);
	for (int i = 0; i < n_doges; i++) {
		for (int j = 0; j < n_doges; j++) {
			if (pillars[doges[i].pillar].dist(pillars[doges[j].pillar]) <= doges[i].power) {
				uf.merge(doges[i].pillar, doges[j].pillar);
			}
		}
	}

	{ // builds the convex hulls
		vector<int> vis(n_pillars);
		for (int i = 0; i < n_pillars; i++) if (!vis[uf.find(i)]) {
				vis[uf.find(i)] = 1;
				vector<pt> points;
				for (int j = 0; j < n_pillars; j++) {
					if (uf.find(i) == uf.find(j)) points.emplace_back(pillars[j].x, pillars[j].y);
				}
				points = pt::convexHull(points);
				double total = pt::polygonArea(points);

				uf.area[uf.find(i)] = total;
				set<pt> current;
				for (pt pp : points) current.insert(pp);

				for (int j = 0; j < n_pillars; j++) {
					if (uf.find(i) == uf.find(j)) {
						damage[j] += total;
					}
				}
			}
	}

	for (int i = 0; i < n_pillars; i++) {
		for (int j = 0; j < n_pillars; j++) {
			if (pillars[i].dist(pillars[j]) <= r && pillars[i].z >= pillars[j].z) {
				edges[i].eb(j, damage[j] + pillars[i].z - pillars[j].z);
			}
		}
	}

	double ans = dijkstra(location, n_pillars);
	if (ans > health) ans = -1;
	else ans = health - ans;
	printf("%.7lf\n", ans);
}
