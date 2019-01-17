#include <bits/stdc++.h>
using namespace std;

#define pb push_back
const int MAXN = 200010;

int r[MAXN], ans[MAXN];
pair<int, int> p[MAXN];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", r+i);
		p[i] = make_pair(r[i], i);
	} 

	sort(p+1, p+n+1);

	int ind = 0, val = 0;
	for (int i = 1; i <= n; i++) {
		if (p[i].first > val) {
			val = p[i].first;
			ind = i - 1;
		}
		ans[p[i].second] = ind;
	}

	for (int i = 0; i < k; i++) {
		int u, v; scanf("%d%d", &u, &v);

		if (r[u] > r[v]) ans[u]--;
		if (r[v] > r[u]) ans[v]--;
	}

	for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	printf("\n");
}