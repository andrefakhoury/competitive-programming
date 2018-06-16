#include <bits/stdc++.h>

using namespace std;

vector<int> vec, ans;

int main () {
	int n, m, x; scanf("%d", &n);
	while(n--) {
		vec.clear(); ans.clear();
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d", &x);
			if (x%2) vec.push_back(x);
		}
		sort(vec.begin(), vec.end());

		int i, j;
		for (i = 0, j = vec.size()-1; i < j; i++, j--) {
			ans.push_back(vec[j]);
			ans.push_back(vec[i]);
		}
		if (vec.size()%2) ans.push_back(vec[j]);

		for (i = 0; i < ans.size(); i++) {
			printf("%d", ans[i]); if (i != ans.size()-1) printf(" ");
		}
		printf("\n");
	}	
}