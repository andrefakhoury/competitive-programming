#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cerr << "[" << #x << "]: " << x << endl
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

const int MAXN = 3e5 + 5, INF = 0x3f3f3f3f;
inline void _solve_(int __ntest__) {
	printf("Case #%d:\n", __ntest__);

	int n; rd(n);
	double p; scanf("%lf", &p);

	int N = n * (n - 1) / 2;

	vector<vector<double>> prob(n, vector<double>(n-1, 1.0));
	for (int match = 1; match < n-1; match++) {
		for (int i = 0; i < n; i++) {

			for (int p1 = 0; p1 < n; p1++) {
				for (int p2 = p1 + 1; p2 < n; p2++) {
					prob[p1][match-1] * prob[p2][match-1];

				}
			}



			double wait = (N - (n-1)) * ();
			double lose = n - i - 1;
			double winn = i;

			prob[i][match] = (1.0 * wait + (1 - p) * lose + p * winn);
			prob[i][match] = prob[i][match-1] * prob[i][match] / (wait + lose + winn);

			printf("[%d %d] {%.2lf %.2lf %.2lf} %.5lf\n", i, match, wait, lose, winn, prob[i][match]);
		}
	}

	for (int i = 0; i < n; i++) {
		double answer = 0;
		for (int j = 0; j < n-1; j++)
			answer += prob[i][j];
		printf("%.10lf\n", answer);
	}
}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL); int __T__; cin >> __T__;
	int __T__; rd(__T__);
	for (int __i__ = 1; __i__ <= __T__; __i__++) {
		cerr << __i__ << endl;
		_solve_(__i__);
	}
	return 0;
}