#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e3 + 5;

char aux[50];

int mat[MAXN][MAXN];
int ord[MAXN][MAXN];

int ant(int i, int n) {
	return i - 1 == 0 ? n : i - 1;
}

int nxt(int i, int n) {
	return i + 1 == n ? 1 : i + 1;
}

void chooseNext(int& i, int& j, int n, int m) {
	int M = max({mat[ant(i, n)][nxt(j, m)], mat[i][nxt(j, m)], mat[nxt(i, n)][nxt(j, m)]});

	if (M == mat[ant(i, n)][nxt(j, m)]) {
		i = ant(i, n);
	} else if (M == mat[i][nxt(j, m)]) {
		i = i;
	} else {
		i = nxt(i, n);
	}

	j = nxt(j, m);
}

int main() {
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++)
		scanf("%d", &mat[i][j]);


	memset(ord, -1, sizeof ord);
	int i = 1, j = 1, N = -1;
	while(ord[i][j] == -1) {
		ord[i][j] = ++N;
		chooseNext(i, j, n, m);
	}

	int q; scanf("%d", &q);

	int cur = 0, x = 1, y = 1;
	while(q--) {
		scanf(" %s", aux);
		if (aux[0] == 'm') {
			int k; scanf("%d", &k);

			int J = (y + k - 1) % m + 1;
			for (int I = 1; I <= N; I++) {
				if (ord[I][J] == -1) continue;
				if (ord[I][J] > )
			}


		} else {
			int a, b, c; scanf("%d%d%d");
		}


	}
}