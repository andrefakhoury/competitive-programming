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

/**
 * 2-Dimensional Point
 * @tparam T type of coordinates
 */
template <typename T=long long>
class Point {
public:
	T x, y;

	static constexpr double EPS = 1e-9;

	Point() : x{}, y{} {}
	Point(T x, T y) : x{x}, y{y} {}

	template<typename Tp>
	inline Point<T>& operator=(Point<Tp> const& rhs) const {
		this->x = static_cast<T>(rhs.x);
		this->y = static_cast<T>(rhs.y);
		return *this;
	}

	template<typename Tp>
	inline Point<T> operator-(Point<Tp> const& rhs) const { return Point(x - rhs.x, y - rhs.y); }

	template<typename Tp>
	inline Point<T> operator+(Point<Tp> const& rhs) const { return Point(x + rhs.x, y + rhs.y); }

	template<typename Tp>
	inline Point<T> operator/(Tp const& k) const { return Point<T>(x/k, y/k); }

	template<typename Tp>
	inline Point<T> operator*(Tp const& k) const { return Point<T>(x*k, y*k); }

	template<typename Tp> // cross product
	inline T operator^(Point<Tp> const& rhs) const { return x * rhs.y - y * rhs.x; }

	template<typename Tp> // dot product
	inline T operator*(Point<Tp> const& rhs) const { return x * rhs.x + y * rhs.y; }

	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }

	template <typename Ty>
	inline double dist(Point<Ty> const& p) { return (p - *this).len(); }

	template <typename Ty>
	inline T dist2(Point<Ty> const& p) { return (p - *this).len2(); }

	inline bool operator<(Point const& rhs) const { return make_pair(x, y) < make_pair(rhs.x, rhs.y); }

	// orthogonal projection
	inline double proj(Point const& b) const { return static_cast<double>((*this)*b) / b.len2(); }

	// -1 if negative, 0 if 0 and 1 if positive
	template <typename Tp>
	inline static char sign(Tp x) { return x < EPS ? -1 : x > EPS ? 1 : 0; }

	// sign of multiplication a*b
	template <typename Ta, typename Tb>
	inline static char sig_mul(Ta const& a, Tb const& b) { return sign(a) * sign(b); }

	// distance of *this to a->b. If needed, the closest point is "Point c", just return it!
	inline double distToSegment(Point const& a, Point const& b) const {
		Point p = *this;
		if ((a - b).len() <= EPS) return (p - a).len();
		Point ap = p - a;
		Point ab = b - a;
		double u = ap.proj(ab);
		u = max(min(u, 1.), 0.);
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

	// Orientation of AC relative to AB. 0 = collinear; -1: ccw, 1: cw
	inline static char orientation(Point const& a, Point const& b, Point const& c) { return sign((b-a)^(c-a)); }

	// returns whether B lies on 1D segment AC
	inline static bool onSegment1D(Point const& a, Point const& b, Point const& c) {
		return b.x <= max(a.x, c.x) && b.x >= min(a.x, c.x) && b.y <= max(a.y, c.y) && b.y >= min(a.y, c.y);
	}

	// returns whether (a, b) intersects with (c, d)
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

	inline void read() { rd(x, y); }
};

using pt = Point<ll>;

inline void _solve_(int testCase) {
	pt li, lf;
	li.read(); lf.read();

	pt a, b, c, d;
	a.read(); c.read();

	pii x = {min(a.x, c.x), max(a.x, c.x)};
	pii y = {min(a.y, c.y), max(a.y, c.y)};

	a = {x.fi, y.se};
	b = {x.fi, y.fi};
	c = {x.se, y.fi}; // a d
	d = {x.se, y.se}; // b c

	bool ans = false;
	ans |= pt::intersect(li, lf, a, b);
	ans |= pt::intersect(li, lf, b, c);
	ans |= pt::intersect(li, lf, c, d);
	ans |= pt::intersect(li, lf, d, a);

	puts(ans ? "T" : "F");
}

int main() {
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) _solve_(__i__);
	return 0;
}