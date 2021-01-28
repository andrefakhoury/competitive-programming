#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

/** ==== GEOMETRY NOTEBOOK ========================================================================================== */
template<typename T> struct Point {
	T x, y;

	static constexpr double EPS = 1e-12;

	Point() : x(), y() {}
	Point(T x, T y) : x(x), y(y) {}
	template<typename Tp> Point(Point<Tp> p) : x(p.x), y(p.y) {}

	// basic operators
	template<typename Tp> Point<T> operator+(Point<Tp> const& p) const { return Point<T>(x + p.x, y + p.y); }
	template<typename Tp> Point<T> operator-(Point<Tp> const& p) const { return Point<T>(x - p.x, y - p.y); }
	template<typename Tp> Point<T> operator*(Tp&& p) const { return Point<T>{x * p, y * p}; }
	template<typename Tp> Point<T> operator/(Tp&& p) const { return Point<T>{x / p, y / p}; }
	template<typename Tp> Point<T> operator%(Tp&& p) const { return Point<T>{x % p, y % p}; }

	template<typename Tp> Point<T>& operator+=(Point<Tp> const& p) { return (*this) = (*this) + p; }
	template<typename Tp> Point<T>& operator-=(Point<Tp> const& p) { return (*this) = (*this) - p; }
	template<typename Tp> Point<T>& operator*=(Tp&& p) { return (*this) = (*this) * p; }
	template<typename Tp> Point<T>& operator/=(Tp&& p) { return (*this) = (*this) / p; }
	template<typename Tp> Point<T>& operator%=(Tp&& p) { return (*this) = (*this) % p; }

	template<typename Tp> bool operator<(Point<Tp> const& p) const { return x == p.x ? y < p.y : x < p.x; }
	template<typename Tp> bool operator==(Point<Tp> const& p) const { return x == p.x && y == p.y; }

	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }
	template<typename Tp> inline T dist2(Point<Tp> const& p) const { return (*this - p).len2();  }
	template<typename Tp> inline double dist(Point<Tp> const& p) const { return hypot(x - p.x, y - p.y); }

	template<typename Tp> inline T dot(Point<Tp> const& p) const { return x * p.x + y * p.y; }
	template<typename Tp> inline T cross(Point<Tp> const& p) const { return x * p.y - y * p.x; }
	template<typename Tp1, typename Tp2> inline T cross(Point<Tp1> const& a, Point<Tp2> const& b) const { return (a - *this).cross(b - *this); }

	template <typename Tp> inline static char sign(Tp x) { return abs(x) < EPS ? 0 : x > 0 ? 1 : -1; }

	/** Orientation of (*this) according to segment AB. 0: collinear, 1: right, -1: left */
	inline char orientation(Point const& a, Point const& b) const { return sign((*this - b).cross(b - a)); }

	/** Orthogonal projection of vector (*this) on vector u.
	 * The point of projection of AB on AC will be at A + AC * AB.proj(AC). */
	inline double proj(Point const& u) const { return static_cast<double>(u.dot(*this)) / u.len2(); }

	/** Distance from (*this) to segment AB */
	inline double dist_to_segment(Point const& a, Point const& b) const {
		Point p = *this;
		if (a.dist2(b) <= EPS) return p.dist(a);
		Point<double> ap = p - a, ab = b - a;
		// if projection doesnt lie on segment, the minimum distance will be to A or B
		double u = clamp(ap.proj(ab), 0., 1.);
		Point<double> c = ab * u + a;
		return p.dist(c);
	}

	/** Checks whether point (*this) is in segment AB */
	inline bool in_segment(Point const& a, Point const& b) const {
		Point<T> AB = b - a, AP = (*this) - a;
		return sign(AB.cross(AP)) == 0 && AB.dot(AP) >= 0 && AB.dot(AP) <= AB.len2();
	}
};

/** returns 2 * area(polygon) */
template<typename T> T shoelace2(vector<Point<T>> const& p) {
	T ans = 0; int n = p.size();
	for (int i = 0, j = n-1; i < n; j = i, i++) ans += p[i].cross(p[j]);
	return abs(ans);
}

/** return the minimum distance^2 between 2 points in the plane */
template<typename T> T closest_pair_distance2(vector<Point<T>> p) {
	sort(p.begin(), p.end());

	vector<Point<T>> strip(p.size());
	auto find_closest = [&](auto&& find_closest, vector<Point<T>>& p, int l, int r)->T {
		if (r - l <= 0) return numeric_limits<T>::max();

		int m = (l + r) / 2;
		T distL = find_closest(find_closest, p, l, m);
		T distR = find_closest(find_closest, p, m + 1, r);
		T dist = min(distL, distR);

		int strip_index = 0;
		for (int i = l, j = m + 1; i <= m || j <= r; ) {
			if (j > r || (i <= m && p[i].y < p[j].y)) strip[strip_index++] = p[i++];
			else strip[strip_index++] = p[j++];
		}
		for (int i = l; i <= r; i++) p[i] = strip[i - l];

		strip_index = 0;
		for (int i = l; i <= r; i++) if ((p[i].x - p[m].x) * (p[i].x - p[m].x) < dist)
			strip[strip_index++] = p[i];

		for (int i = 0; i < strip_index; i++) {
			for (int j = i + 1; j < strip_index && (strip[j].y - strip[i].y) * (strip[j].y - strip[i].y) < dist; j++) {
				dist = min(dist, strip[i].dist2(strip[j]));
			}
		}

		return dist;
	};

	return find_closest(find_closest, p, 0, (int) p.size() - 1);
}

/** Checks whether 1-dimensional segments [a, b] and [c, d] intersect */
template<typename T> bool segments_intersect_1d(T a, T b, T c, T d) {
	if (a > b) swap(a, b);
	if (c > d) swap(c, d);
	return max(a, c) <= min(b, d);
}

/** Checks whether segments AB and CD intersect */
template <typename T> bool segments_intersect(Point<T> const& a, Point<T> const& b, Point<T> const& c, Point<T> const& d) {
	if (c.cross(a, d) == 0 && c.cross(b, d) == 0)
		return segments_intersect_1d(a.x, b.x, c.x, d.x) && segments_intersect_1d(a.y, b.y, c.y, d.y);
	return Point<T>::sign(a.cross(b, c)) != Point<T>::sign(a.cross(b, d)) &&
		   Point<T>::sign(c.cross(d, a)) != Point<T>::sign(c.cross(d, b));
}

/** Check if point p is inside polygon. Return: 0: outside, 1: inside, 2: boundary.
 * BE CAREFUL: inf has to be greater than any other point, to make sure it isn't collinear with any edge */
template<typename T> int in_polygon(Point<T> p, vector<Point<T>> const& v) {
	int n = v.size(), count = 0;

	const T inf = 2e9;
	Point<T> p2{p.x + 1, inf};
	for (int i = 0, j = n-1; i < n; j = i, i++) {
		if (p.in_segment(v[i], v[j])) return 2;
		count += segments_intersect(p, p2, v[i], v[j]);
	}

	return count % 2;
}

/** Returns whether polygon points are in clockwise or counter-clockwise order */
template<typename T> bool is_clockwise(vector<Point<T>> const& v) {
	T area = 0; int n = v.size();
	for (int i = 0, j = n - 1; i < n; j = i, i++) area += v[i].cross(v[j]);
	return area >= 0;
}

/** Count integer (lattice) points inside and on boundary of polygon (can be concave)
 * BE CAREFUL: T must be INTEGER!!! */
template<typename T> pair<T, T> count_lattice_points(vector<Point<T>> const& v) {
	/** Pick's theorem: A = i + b/2 - 1 (area = inner_lattice + boundary_lattice/2 - 1) */
	pair<T, T> ans = {0, 0}; // <inside, boundary>
	T area2 = 0;
	int n = v.size();
	for (int i = 0, j = n-1; i < n; j = i, i++) {
		Point<T> dif = v[i] - v[j];
		dif.x = abs(dif.x), dif.y = abs(dif.y);
		ans.se += gcd(dif.x, dif.y);
		area2 += v[i].cross(v[j]);
	}
	area2 = abs(area2);
	ans.fi = (area2 - ans.se + 2) / 2;
	return ans;
}

/** Convex hull excluding collinear points. O(n)
 * To include collinear points, change the <= operators of orientation to < */
template<typename T> vector<Point<T>> convex_hull(vector<Point<T>> v) {
	int n = v.size();
	if (n <= 2) return v;

	sort(v.begin(), v.end());

	vector<Point<T>> ch(2 * n);
	int sz = 0;

	for (int i = 0; i < n; i++) {
		while(sz > 1 && v[i].orientation(ch[sz - 2], ch[sz - 1]) < 0) sz--;
		ch[sz++] = v[i];
	}
	for (int i = n-2, up_sz = sz; i >= 0; i--) {
		while(sz > up_sz && v[i].orientation(ch[sz - 2], ch[sz - 1]) < 0) sz--;
		ch[sz++] = v[i];
	}

	ch.resize(sz - 1);
	return ch;
}

template<typename T> istream& operator>>(istream& in, Point<T>& p) { return in >> p.x >> p.y; }
template<typename T> ostream& operator<<(ostream& out, Point<T>& p) { return out << p.x << ' ' << p.y; }
using pt = Point<ll>;
/** ==== GEOMETRY NOTEBOOK ========================================================================================== */

inline void run_test(int test_number) {
	int n; rd(n);
	vector<pt> a(n);
	for (int i = 0; i < n; i++) rd(a[i]);
	vector<pt> ch = convex_hull(a);
	print(ch.size());
	for (pt x : ch) print(x);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int n_tests = 1;
	for (int i = 1; i <= n_tests; i++) run_test(i);
}