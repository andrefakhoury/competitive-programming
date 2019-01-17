#include <bits/stdc++.h>

using namespace std;

int main() {
	queue<int> a, c;
	int n, m, x; scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		c.push(x);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x);
		a.push(x);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a.size() && a.front() >= c.front()) {
			ans++;
			a.pop();
		}
		c.pop();
	}

	printf("%d\n", ans);
	return 0;
}