#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
	#define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
	#define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
	char c; while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
	x = (x << 3) + (x << 1) + c - '0';
	if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

vector<int> D;

bool solve(int i, int j, vector<vector<int>>& a, int n, int k) {
	if (i == n) return solve(0, j+1, a, n, k);
	if (j == n) {
		int sum = 0;
		for (int x = 0; x < n; x++) {
			sum += a[x][x];
		}
		return sum == k;
	}

	for (int d : D) {
		bool ok = true;
		for (int I = 0; I < n; I++) ok &= a[I][j] != d;
		for (int I = 0; I < n; I++) ok &= a[i][I] != d;
		if (!ok) continue;

		a[i][j] = d;
		if (solve(i+1, j, a, n, k))
			return true;
		a[i][j] = 0;
	}

	return false;
}

inline void _solve_(int ttcs) {
	int n, k; rd(n, k);
	vector<vector<int>> a(n, vector<int>(n));
	D = vector<int>(n);
	iota(D.begin(), D.end(), 1);
	shuffle(D.begin(), D.end(), rng);
	bool ans = solve(0, 0, a, n, k);

	printf("Case #%d: ", ttcs);
	if (!ans) printf("IMPOSSIBLE\n");
	else {
		printf("POSSIBLE\n");
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
}

int main() {
	int __T__; rd(__T__);
	for (int ttcs = 1; ttcs <= __T__; ttcs++) _solve_(ttcs);
	return 0;
}