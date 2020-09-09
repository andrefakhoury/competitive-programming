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

const int MAXN = 100 + 5, INF = 0x3f3f3f3f;

pair<double, int> prob[100][100]; // prob[i][match]

void solve(vector<int> cur, double ac, double p, int n, int match) {

	for (int p1 = 0; p1 < n; p1++) if (cur[p1]) {
		prob[p1][match].first += ac;
		prob[p1][match].second++;
		for (int p2 = p1 + 1; p2 < n; p2++) if (cur[p2]) {
			// batalha entre p1 e p2

			cur[p1] = 0;
			solve(cur, ac * p, p, n, match + 1);
			cur[p1] = 1;
			cur[p2] = 0;
			solve(cur, ac * (1 - p), p, n, match + 1);
			cur[p2] = 1;
		}
	}
}

int main() {
	int n; rd(n);
	double p; scanf("%lf", &p);

	vector<int> cur(n, 1);
	solve(cur, 1, p, n, 1);

	for (int i = 0; i < n; i++) {
		double ans = 0;
		for (int j = 1; j < n; j++) {
			ans += j * prob[i][j].fi / prob[i][j].se;
			printf("[%d %d] : %.3lf/%d = %.5lf\n", i, j, prob[i][j].fi, prob[i][j].se, prob[i][j].fi/prob[i][j].se);
		}
		printf(">>%.5lf\n", ans);
	}


}