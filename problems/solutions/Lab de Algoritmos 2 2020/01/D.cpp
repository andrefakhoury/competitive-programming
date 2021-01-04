#include <bits/stdc++.h>
using namespace std;

int main() {
	int T; scanf("%d", &T);
	for (int cs = 1; cs <= T; cs++) {
		int n; scanf("%d", &n);
		vector<vector<int>> a(n);

		map<int, int> f;
		for (vector<int>& v : a) {
			int k; scanf("%d", &k);
			v.resize(k);
			for (int& i : v) scanf("%d", &i);
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			for (int i : v) f[i]++;
		}

		int cnt = 0;
		for (auto p : f) cnt += p.second == 1;

		printf("Case %d: ", cs);
		for (int i = 0; i < n; i++) {
			if (i) printf(" ");

			int cur = 0;
			for (int x : a[i]) cur += f[x] == 1;
			printf("%.6lf%%", cnt == 0 ? 0 : 100.0 * cur / cnt);
		}
		printf("\n");
	}
}