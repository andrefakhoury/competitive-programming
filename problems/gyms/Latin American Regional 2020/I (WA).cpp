#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cout << #x << ": " << x << endl)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const double EPS = 1e-12;
template<typename T> inline char sign(T x) { return abs(x) < EPS ? 0 : x > 0 ? 1 : -1; }
template<typename T> struct Point {
	T x, y;

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

	template<typename Tp> ll operator^(Tp&& p) const { return x * p.y - p.x * y; }
	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }
	template<typename Tp> inline T dist2(Point<Tp> const& p) const { return (*this - p).len2();  }
	template<typename Tp> inline double dist(Point<Tp> const& p) const { return hypot(x - p.x, y - p.y); }

	template<typename Tp> inline T dot(Point<Tp> const& p) const { return x * p.x + y * p.y; }    // |u| * |v| * cos(alpha)
	template<typename Tp> inline T cross(Point<Tp> const& p) const { return x * p.y - y * p.x; }  // |u| * |v| * sin(alpha)
	template<typename Tp1, typename Tp2> inline T dot(Point<Tp1> const& a, Point<Tp2> const& b) const { return (a - *this).dot(b - *this); }
	template<typename Tp1, typename Tp2> inline T cross(Point<Tp1> const& a, Point<Tp2> const& b) const { return (a - *this).cross(b - *this); }

	/** Orientation of (*this) according to segment AB. 0: collinear, 1: right, -1: left */
	inline char orientation(Point const& a, Point const& b) const { return sign((*this - b).cross(b - a)); }

	/** Orthogonal projection of vector (*this) on vector u.
	 * The point of projection of AB on AC will be at A + AC * AB.proj(AC). */
	inline double proj(Point const& u) const { return static_cast<double>(u.dot(*this)) / u.len2(); }

	/** Distance from (*this) to segment AB */
	inline double dist_to_segment(Point const& a, Point const& b) const {
		Point<T> p = *this;
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

template<typename T> istream& operator>>(istream& in, Point<T>& p) { return in >> p.x >> p.y; }
template<typename T> ostream& operator<<(ostream& out, Point<T>& p) { return out << p.x << ' ' << p.y; }
using pt = Point<ll>;




const int N = 307;
ll memo[N][N][N];
int n; 

pt h, g;
const int M = 1e9 + 7;

const pt ptu{0, 1};
pt vec[N];

bool getp(pt p) {
  return ptu.cross(p) > 0 || (ptu.cross(p) == 0 && ptu.dot(p) > 0);
}

bool cmp(pt pta, pt ptb) {
  pt a = pta - g;
  pt b = ptb - g;
  return (getp(a) == getp(b) && a.cross(b) > 0) || (getp(a) && !getp(b));
}

ll solve(int cur, int last, int last2) {
	if(cur == n) return 0;
	ll & st = memo[cur][last][last2 + 1];
	if(st == -1) {
		st = 0;
		pt u = vec[last] - (last2 >= 0? vec[last2] : g);
		pt v = vec[cur] - vec[last];
		if((u^v) > 0 and h.orientation(vec[last], vec[cur]) == -1) {
			st += solve(cur+1, cur, last);
			st %= M;
			if(h.orientation(vec[last], g) == -1) {
				st += 1;
			}
		}
		st += solve(cur+1, last, last2);
	}
	return st;
}


int main() {
	memset(memo, -1, sizeof memo);
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> h;
	cin >> g;

	cin >> n;

	if(n <= 2) {
		cout << 0 << '\n';
		return 0;
	}
	for(int i = 0; i < n; i++) {
		cin >> vec[i];
	}

	sort(vec, vec + n, cmp);

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		ans = (ans + solve(0, i, -1)) % M;
	}
	cout << ans << '\n';
}