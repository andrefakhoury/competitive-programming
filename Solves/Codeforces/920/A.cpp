#include <bits/stdc++.h>

using namespace std;

#define pb push_back
int ans[300];

int main() {
	int t; scanf("%d", &t);

	int n, k, x;

	while(t--) {
		vector<int> w;
		memset(ans, 0x3f3f3f3f, sizeof ans);
		scanf("%d%d", &n, &k);
		
		for (int i = 0; i < k; i++) {
			scanf("%d", &x); w.pb(x);
		}


		//  1 2 3 4 5
		//

		for (int i = 0; i < k; i++) {
			for (int j = 1; j <= n; j++) {
				ans[j] = min(ans[j], (w[i]-j+1 <= 0) ? j-w[i]+1 : w[i]-j+1);
			}
		}
		int res = 0;
		for (int i = 1; i <= n; i++)
			res = max(res, ans[i]);
		printf("%d\n", res);

	}

	return 0;
}