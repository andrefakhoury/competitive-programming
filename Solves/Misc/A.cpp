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
template <class... Args> inline void rd(Args&... args) { (rd(args), ...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

/**
 * 2-Dimensional Point
 * @tparam T type of coordinates
 * @tparam D type of floating points (used in distances and stuff)
 */
template <typename T=int, typename D=double>
class Point {
public:
	T x, y;

	static constexpr D EPS = static_cast<D>(1e-9);

	Point() : x{}, y{} {}
	Point(T x, T y) : x{x}, y{y} {}

	template<typename Tp, typename Dp>
	inline Point<T, D>& operator=(Point<Tp, Dp> const& rhs) const {
		this->x = static_cast<T>(rhs.x);
		this->y = static_cast<T>(rhs.y);
		return *this;
	}

	template<typename Tp, typename Dp>
	inline Point<T, D> operator-(Point<Tp, Dp> const& rhs) const { return Point(x - rhs.x, y - rhs.y); }

	template<typename Tp, typename Dp>
	inline Point<T, D> operator+(Point<Tp, Dp> const& rhs) const { return Point(x + rhs.x, y + rhs.y); }

	template<typename Tp>
	inline Point<T, D> operator/(Tp const& k) const { return Point<T, D>(x/k, y/k); }

	template<typename Tp>
	inline Point<T, D> operator*(Tp const& k) const { return Point<T, D>(x*k, y*k); }

	template<typename Tp, typename Dp> // cross product
	inline T operator^(Point<Tp, Dp> const& rhs) const { return x * rhs.y - y * rhs.x; }

	template<typename Tp, typename Dp> // dot product
	inline T operator*(Point<Tp, Dp> const& rhs) const { return x * rhs.x + y * rhs.y; }

	template <typename Ty, typename Dp>
	inline T len2(Point<Ty, Dp> const& p) const { return p.x * p.x + p.y * p.y; }

	template <typename Ty, typename Dp>
	inline D len(Point<Ty, Dp> const& p) const { return sqrt(static_cast<D>(p.x * p.x + p.y * p.y)); }

	inline bool operator<(Point const& rhs) const { return make_pair(x, y) < make_pair(rhs.x, rhs.y); }
	inline bool operator==(Point const& rhs) const { return make_pair(x, y) == make_pair(rhs.x, rhs.y); }

	// orthogonal projection
	inline D proj(Point const& b) const { return static_cast<D>((*this)*b) / b.len2(); }

	// -1 if negative, 0 if 0 and 1 if positive
	inline static char sign(T x) { return x < T{} ? -1 : x > T{} ? 1 : 0; }

	// distance of *this to a->b. If needed, the closest point is "Point c", just return it!
	inline D distToSegment(Point const& a, Point const& b) const {
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
	inline static vector<Point<T, D>> convexHull(vector<Point<T, D>> p) {
		if (p.size() <= 2u) return p;

		int n = p.size(), k = 0;
		vector<Point<T, D>> H(2*n);

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
};

int main() {
	vector<Point<>> points(3);

	for (auto& p : points) {
		rd(p.x, p.y);
	}

	vector<Point<>> answer;
	answer.reserve(3);
	for (int x = -3000; x <= 3000; x++) {
		for (int y = -3000; y <= 3000; y++) {
			points.push_back({x, y});
			if (points[0] == points[3] or points[1] == points[3] or points[2] == points[3]) {
				points.pop_back();
				continue;
			}

			bool ok = false;
			sort(points.begin(), points.end());
			if (((points[1] - points[0]) ^ (points[3] - points[2])) == 0 &&
			    ((points[2] - points[0]) ^ (points[3] - points[1])) == 0) {
					ok = true;
				}
			if (ok) {
				answer.push_back({x, y});
			}

			points.erase(find(points.begin(), points.end(), Point<>{x, y}));
		}
	}

	printf("%ld\n", answer.size());
	for (auto& p : answer) {
		printf("%d %d\n", p.x, p.y);
	}
}