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

double get(vector<double> p) {
	int n = p.size();
	double ans = 0;
	for (int i = 0; i < n; i++) {
		double cur = p[i];
		for (int j = 0; j < n; j++) if (i != j) {
			cur *= 1 - p[j];
		}
		ans += cur;
	}

	return ans;
}

vector<double> go(vector<double> const& p, int l, int r) {
	vector<double> ret;
	for (int i = l; i <= r; i++)
		ret.pb(p[i]);
	return ret;
}

vector<double> get_all(vector<double> const& p, int i, int j) {
	vector<double> c1 = go(p, 0, i);
	vector<double> c2 = go(p, j, (int) p.size() - 1);
	for (double c : c2) c1.push_back(c);
	return c1;
}

int main() {
	int n; scanf("%d", &n);
	vector<double> d(n);
	for (int i = 0; i < n; i++)
		scanf("%lf", &d[i]);

	double ans = 0;
	sort(d.rbegin(), d.rend());

	for (int i = 0; i < n; i++) {
		ans = max(ans, get(get_all(d, i, n)));
	}

	printf("%.12lf\n", ans);
}