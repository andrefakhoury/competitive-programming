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
const int QT_POINTS = 3e4;

struct Point {
	double x, y;

	inline Point(double x, double y) : x(x), y(y) {}
	inline Point() {}

	inline Point operator+(Point const& p) const { return {x + p.x, y + p.y}; }
	inline Point operator-(Point const& p) const { return {x - p.x, y - p.y}; }
	inline double operator^(Point const& p) const { return x * p.y - y * p.x; }
	inline bool operator<(Point const& p) const { return mk(x, y) < mk(p.x, p.y); }
	inline double dist(Point const& p) { return hypot(x-p.x, y-p.y); }
};

inline vector<Point> convex_hull(vector<Point> p) {
	if (p.size() <= 2u) return p;

	int n = p.size(), k = 0;
	vector <Point> H(2*n);

	sort(p.begin(), p.end());

	for (int i = 0; i < n; i++) {
		while (k >= 2 and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
		H[k++] = p[i];
	}

	for (int i = n-2, t = k+1; i >= 0; i--) {
		while (k >= t and ((H[k-1]-H[k-2])^(p[i]-H[k-2])) <= 0.0) k--;
		H[k++] = p[i];
	}

	H.resize(k-1);
	return H;
}

const double PI = acos(-1);

int main() {
	int n; rd(n);

	vector<Point> points;
	points.reserve(n * QT_POINTS);

	for (int i = 1; i <= n; i++) {
		int x, y, r; rd(x, y, r);
		r += 10;

		double alpha_d = 2 * PI / QT_POINTS, alpha = 0;
		for (int p = 0; p < QT_POINTS; p++) {
			points.emplace_back(x + r * cos(alpha), y + r * sin(alpha));
			alpha += alpha_d;
		}
	}

	points = convex_hull(points);

	int N = points.size();
	double ans = points[0].dist(points[N-1]);
	for (int i = 1; i < N; i++) ans += points[i].dist(points[i-1]);
	printf("%.10lf\n", ans);
}