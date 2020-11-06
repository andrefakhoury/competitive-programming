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
	x = neg ? -x : x, 1; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
inline double _solve_(double a, double b, double c) {
	double x[3] = {a, b, c};
	sort(x, x+3);

	double ret = -1;
	if (x[0] > 0) {
		a *= a, b *= b, c *= c;
		ret = 2 * (a * b + a * c + b * c);
		ret -= a * a + b * b + c * c;
		if (ret <= 0) return -1;
		ret = 1.0 / 3.0 * sqrt(ret);
	}

	return ret;
}

int main() {
	double a, b, c;
	while(~scanf("%lf%lf%lf", &a, &b, &c)) {
		printf("%.3lf\n", _solve_(a, b, c));
	}
	return 0;
}