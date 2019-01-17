#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	vector<int> t(n);
	for (int i = 0; i < n; i++) scanf("%d", &t[i]);
	sort(t.begin(), t.end());
	
	int ans = 0;
	for (int i = 1; i < t.size(); i += 2) {
		ans += t[i] - t[i-1];
	}

	printf("%d\n", ans);
}