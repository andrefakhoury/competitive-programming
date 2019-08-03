#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e3 + 5;

bool check(int n, int k) {
	if (n%2 == 1 && k == 2) return false;

	if (k%2 == 1) {
		if (k*(k-1) / 2 > n) return false;
		if (k*(k-1) / 2 + 1 == n) return false;
	} else {
		if ((k*k) / 2 > n) return false;
	}

	return true;	
}

vector<int> edges[MAXN];
int color[MAXN];

int dfs() {
	
}

int main() {
	// freopen("achromatic.in", "r", stdin);
	// freopen("achromatic.out", "w", stdout);

	int n, ans = -1; scanf("%d", &n);

	for (int k = 2; k <= n; k++)
		if (check(n, k)) ans = k;

	for (int i = 1; i <= ans; i++) {
		for (int j = i+1; j <= ans; j++) {
			edges[i].push_back(j);
			edges[j].push_back(i);
		}
	}

	int u = 0;

	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		printf("%d ", color[i]);
	printf("\n");

	return 0;
}