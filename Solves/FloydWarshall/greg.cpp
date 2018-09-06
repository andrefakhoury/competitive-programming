#include <bits/stdc++.h>

using namespace std;
#define MAXN 510
#define pb push_back
#define INF (1LL << 48)

typedef long long ll;

ll g[MAXN][MAXN], v[MAXN], use[MAXN], ans[MAXN];

void initi(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			g[i][j] = INF;
}

void input(int n) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> g[i][j];

	for (int i = 1; i <= n; i++) cin >> v[i];
}

void fw(int n) {
	for (int k = n; k > 0; k--) {
		use[v[k]] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				g[i][j] = min(g[i][j], g[i][v[k]]+g[v[k]][j]);
				if (use[i] && use[j]) ans[k] += g[i][j];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL);

	int n; cin >> n;

	initi(n);
	input(n);
	fw(n);

	for (int i = 1; i <= n; i++)
		cout << ans[i] << " \n"[i == n];

	return 0;
}