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
	template <typename Tp> Point<T> operator/(Tp const& p) const { return Point<T>(x / p, y / p); }

	bool operator<(Point const& p) const { return x == p.x ? y < p.y : x < p.x; }
	inline T dot(Point const& p) const { return x * p.x + y * p.y; }
	inline T cross(Point const& p) const { return x * p.y - y * p.x; }

	inline T len2() const { return x * x + y * y; }
	inline double len() const { return hypot(x, y); }
	inline T dist2(Point const& p) const { return (p - *this).len();  }
	inline double dist(Point const& p) const { return hypot(x - p.x, y - p.y); }
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

		auto f = [&p1, &p2](pt const& p) {
			return p.dist(p1) + p.dist(p2);
		};

		for (int i = 0, j = n - 1; i < n; j = i, i++) {
			pt lo = p[i], hi = p[j], m1, m2;
			for (int ck = 1; ck <= 50; ck++) {
				m1 = lo + (hi - lo) / 3.0;
				m2 = lo + (hi - lo) * 2.0 / 3.0;
				if (f(m1) < f(m2)) hi = m2;
				else lo = m1;
			}
			ans = min(ans, mk(f(lo), lo));
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