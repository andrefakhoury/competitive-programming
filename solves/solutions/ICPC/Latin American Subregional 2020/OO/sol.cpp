// wrong solution

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
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
using ll = long long;
using pii = pair<int, int>;

template <typename T> struct Point {
	T x, y;

	static constexpr double EPS = 1e-9;
	Point() : x{}, y{} {}
	Point(T x, T y) : x{x}, y{y} {}
	template<typename Ty> Point(Ty x, Ty y) { this->x = static_cast<T>(x); this->y = static_cast<T>(y); }
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
	[[nodiscard]] inline double len() const { return hypot(x, y); }
};

template<typename T> ostream& operator<<(ostream& out, Point<T> const& p) { return out << p.x << " " << p.y; }
template<typename T> istream& operator>>(istream& in, Point<T>& p) { return in >> p.x >> p.y; }

using ptl = Point<ll>;
using ptd = Point<double>;

const int MAXN = 1e5;

ptl a[MAXN];
ptl d[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cerr << fixed << setprecision(2); cout << fixed << setprecision(2);

	int n; cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	a[n] = a[0];
	for (int i = 0; i < n; i++) d[i] = a[i+1] - a[i];

	auto go = [&](double deg) {
		double cs = cos(deg), sn = sin(deg);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			double nx = cs * d[i].x + sn * d[i].y;
			if (nx <= 1e-7) continue;
			double ny = cs * d[i].y - sn * d[i].x;
			ans += nx / hypot(nx, ny) * d[i].len();
		}
		return ans;
	};

	const double PI2 = 2 * acos(-1.0);

	int QT = 3;
	double L[] = {0., 1, 2};
	double R[] = {PI2, PI2 + 1, PI2 + 2};

	double ans = 1e18;
	for (int i = 0; i < QT; i++) {
		double lo = L[i], hi = R[i], m1, m2;
		while(hi - lo > 2e-11) {
			m1 = lo + (hi - lo) / 3.;
			m2 = lo + 2. * (hi - lo) / 3.;
			if (go(m1) < go(m2)) hi = m2;
			else lo = m1;
		}
		ans = min(ans, go(lo));
	}

	cout << ans << "\n";
}
