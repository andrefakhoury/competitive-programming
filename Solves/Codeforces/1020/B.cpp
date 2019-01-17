#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int a[MAXN];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int k = 1; k <= n; k++) {
		vector<int> vis(n+1, 0);
		int i;

		for (i = k; vis[i] <= 0; i = a[i]) vis[i]++;
		printf("%d ", i);
	}
	printf("\n");
}