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

template <typename T>
struct Point {
	T x, y;

	static constexpr double EPS = 1e-12;

	Point() : x(), y() {}
	Point(T x, T y) : x(x), y(y) {}

	Point operator+(Point const& p) const { return Point<T>(x + p.x, y + p.y); }
	Point operator-(Point const& p) const { return Point<T>(x - p.x, y - p.y); }
	template <typename Tp> Point<T> operator*(Tp const& p) const { return Point<T>(x * p, y * p); }
	bool operator<(Point const& p) const { return x == p.x ? y < p.y : x < p.x; }
	inline T dot(Point const& p) const { return x * p.x + y * p.y; }
	inline T cross(Point const& p) const { return x * p.y - y * p.x; }

	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }
	inline T dist2(Point const& p) const { return (p - *this).len();  }
	inline double dist(Point const& p) const { return hypot(x - p.x, y - p.y); }

	inline double proj(Point const& b) const { return static_cast<double>(b.dot(*this)) / b.len2(); }

	inline double distToSegment(Point const& a, Point const& b) const {
		Point p = *this;
		if (a.dist2(b) <= EPS) return p.len(a);
		Point ap = p - a, ab = b - a;
		double u = clamp(ap.proj(ab), 0., 1.);
		Point c = a + ab * u;
		return p.dist(c);
	}
};

struct Line {
	double a, b, c;
	Line() :a(0),b(0),c(0) {}
	Line( Point<double> p0, Point<double> p1 ) {
		a = p1.y-p0.y;
		b = p0.x-p1.x;
		c = a*p1.x + b*p1.y;
	}
	bool operator==( Line L ) {
		if( a > L.a )
		{
			return ( a*L.b == L.a*b && b*L.c == L.b*c && a*L.c == c*L.a);
		}
		else
			return ( L.a*b == a*L.b && L.b*c == b*L.c && L.a*c == L.c*a );
	}
	bool parallel( Line L ) {
		return (a*L.b - b*L.a == 0 );
	}
	bool intersect( Line L ) {
		return (a*L.b - b*L.a != 0 );
	}
	Point<double> intersection( Line L ) {
		if( intersect( L ) )
		{
			return Point<double>( double(c*L.b - b*L.c)/double(a*L.b-b*L.a),
								  double(a*L.c - c*L.a)/double(a*L.b-b*L.a)
			);
		}
		else return Point<double>(0,0);
	}
};

template <typename T> istream& operator>>(istream& in, Point<T>& p) { return in >> p.x >> p.y; }
template <typename T> ostream& operator<<(ostream& out, Point<T>& p) { return out << p.x << ' ' << p.y; }
using pt = Point<double>;

inline void run_test() {
	cout << fixed << setprecision(7);

	int n; rd(n);
	vector<pt> p(n);
	for (int i = 0; i < n; i++) rd(p[i]);

	int q; rd(q);

	while(q--) {
		pt p1, p2; rd(p1, p2);
		pair<double, pt> ans = {1e12, pt{}};

		for (int i = 0, j = n - 1; i < n; j = i, i++) {
			pt u = p[i], v = p[j];

			double len = (p1 - u).dot(v - u);
			len /= (v - u).len2();
			pt proj = u + (v - u) * len;
			pt np1 = p1 + (proj - p1) * 2;
			double cur1 = np1.dist(p2);

			Line l1(np1, p2), l2(u, v);
			pt cur2 = l1.intersection(l2);
			ans = min(ans, mk(cur1, cur2));
		}

		cout << ans.fi << " " << ans.se << "\n";
	}

}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

#ifndef LOCAL_PC
	freopen("flags.in", "r", stdin);
#endif

	int T; rd(T);
	for (int cs = 1; cs <= T; cs++) {
		cout << "Case " << cs << ":\n";
		run_test();
	}
}