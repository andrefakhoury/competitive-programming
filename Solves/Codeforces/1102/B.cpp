#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k; scanf("%d%d", &n, &k);
	vector<int> c(n);
	for (int i = 0; i < n; i++) scanf("%d", &c[i]);

	vector<int> ans(n), freq(5001, 0), s(5001, 0), pre(5001, 0);
	for (int i = 0; i < n; i++) pre[c[i]]++;

	for (int i = 0, st = 1; i < n; i++) {
		if (s[c[i]] == 0) {
			s[c[i]] = st;
			st = (st + pre[c[i]] - 1)%k + 1;
		}
	}

	int qtt = 0;
	for (int i = 0; i < n; i++) {
		freq[c[i]]++;
		ans[i] = s[c[i]] + freq[c[i]] - 1;
		if (ans[i] > k) ans[i] = (ans [i] - 1)%k + 1;

		qtt += freq[c[i]] == 1;
		if (freq[c[i]] > k) return !printf("NO\n");
	}

	// if (qtt < k) return !printf("NO\n");

	printf("YES\n");
	for (int i = 0; i < n; i++) printf("%d ", ans[i]);
	return !printf("\n");
}