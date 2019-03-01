#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 400000;

int a[MAXN], acc[MAXN];

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	map<int, int> freq_i, freq_p;
	for (int i = 1; i <= n; i++) {
		acc[i] = acc[i-1] ^ a[i];
		
		if (i%2 == 0) freq_p[acc[i]]++;
		else freq_i[acc[i]]++;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i%2 == 0) {
			freq_p[acc[i]]--;
			ans += freq_i[acc[i-1]];
		} else {
			freq_i[acc[i]]--;
			ans += freq_p[acc[i-1]];
		}
	}

	printf("%lld\n", ans);

	return 0;
}