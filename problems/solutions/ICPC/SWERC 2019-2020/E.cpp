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

using mask = bitset<400>;
void gauss (vector<mask> a, int n, int m, mask& ans) {
	vector<int> where (m, -1);
	for (int col=0, row=0; col<m && row<n; ++col) {
		for (int i = row; i < n; i++) if (a[i][col]) {
			swap (a[i], a[row]);
			break;
		}
		if (!a[row][col]) continue;
		where[col] = row;
		for (int i = 0; i < n; i++) if (i != row && a[i][col])
			a[i] ^= a[row];
		++row;
	}

	ans = {};
	for (int i = 0; i < m; i++) if (~where[i])
		ans[i] = a[where[i]][m];

}

int main() {
	int n, m; rd(n, m);
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; scanf(" %c", &c);
			a[i][j] = c == 'B';
		}
	}

	auto get = [&](int i, int j) { return i * m + j; };
	auto valid = [&](int i, int j) { return i >= 0 && j >= 0 && i < n && j < m; };
	int di[4] = {0, 0, -1, 1};
	int dj[4] = {1, -1, 0, 0};

	vector<mask> bt(n * m);
	for (int i = 0; i < m; i++) bt[i][i] = 1;

	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			int u = get(i, j);
			bt[get(i+1, j)][m] = a[i][j];
			bt[get(i+1, j)] ^= bt[u];

			for (int k = 0; k < 3; k++) {
				int I = i+di[k], J = j+dj[k];
				if (valid(I, J)) {
					int v = get(I, J);
					bt[get(i+1, j)] ^= bt[v];
				}
			}
		}
	}

	vector<mask> A(m);
	for (int j = 0; j < m; j++) {
		A[j] = {};
		A[j][m] = a[n-1][j];
		A[j] ^= bt[get(n-1, j)];

		for (int k = 0; k < 4; k++) {
			int I = (n-1)+di[k], J = j+dj[k];
			if (valid(I, J)) A[j] ^= bt[get(I, J)];
		}
	}

	mask x;
	gauss(A, m, m, x);

	vector<vector<int>> ans(n, vector<int>(m));
	for (int i = 0; i < m; i++) ans[0][i] = x[i];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans[i][j] = bt[get(i, j)][m];
			for (int k = 0; k < m; k++) if (bt[get(i, j)][k])
				ans[i][j] ^= ans[0][k];
		}
	}

	auto check = [&]() {
		vector<vector<int>> xx(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				xx[i][j] ^= ans[i][j];
				for (int k = 0; k < 4; k++) if (valid(i+di[k], j+dj[k]))
					xx[i+di[k]][j+dj[k]] ^= ans[i][j];
			}
		}

		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (xx[i][j] != a[i][j]) return false;
		return true;
	};

	if (!check()) {
		puts("IMPOSSIBLE");
		return 0;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%c ", ans[i][j] ? 'P' : 'A');
		}
		printf("\n");
	}
}