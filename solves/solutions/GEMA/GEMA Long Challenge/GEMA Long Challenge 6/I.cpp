#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e3 + 1;
const int MAXX = 999;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN][MAXN], n, m;
int nxt[MAXN][MAXX]; // nxt[i][j] = row of jump from a[i][1] k times

inline int value_of(pii const& p) {
	return a[p.fi][p.se];
}

inline pii move_next(int x, int y, int delta) {
	y = y%m + 1;
	x = (x - 1 + delta + n) % n + 1;
	return {x, y};
}

inline pii next_block(int const& x, int const& y) {
	pii ret_block = {0, 0};

	for (int delta = -1; delta <= 1; delta++) {
		pii cur_block = move_next(x, y, delta);
		if (value_of(cur_block) > value_of(ret_block))
			ret_block = cur_block;
	}

	return ret_block;
}

inline int move_y(int y, int k) {
	return (y-1+k)%m + 1;
}

int move_x(int const x, int const k) {
	int i = x, j = 1;
	for (int K = 1; K <= k; K++) {
		pii xx = next_block(i, j);
		i = xx.fi, j = xx.se;
	}

	return i;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		nxt[i][0] = i;
		nxt[i][1] = next_block(i, 1).fi;

		int j = 2;
		for (int x = 2, ok = 0; !ok && j != 1; x++) {
			nxt[i][x] = next_block(nxt[i][x-1], move_y(1, x)).fi;
			j++; if (j > m) j = 1, ok = 1;
		}
	}

	int X = 1, Y = 1, Q; scanf("%d", &Q);
	while(Q--) {
		char op; scanf(" %c%*s", &op);

		if (op == 'm') {
			int k; scanf("%d", &k);

			while(k > 0 && X != 1) {
				pii nx = next_block(X, Y);
				X = nx.fi, Y = nx.se;
				k--;
			}

			while(K > 0) {

			}

			printf("%d %d\n", X, Y);
		} else {
			int i, j, x; scanf("%d%d%d", &i, &j, &x);
			a[i][j] = x;
		}
	}

	return 0;
}