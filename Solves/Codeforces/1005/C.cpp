#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 120005;

int n, a[MAXN], p2[31];
map<int, int> f;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		f[a[i]]++;
	}

	p2[0] = 1;
	for (int i = 1; i <= 30; i++) p2[i] = 2 * p2[i-1];

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool flag = true;
		for (int p = 0; p <= 30; p++) {
			if (f[p2[p] - a[i]]) {
				if (p2[p]-a[i] == a[i] && f[p2[p] - a[i]] == 1) continue;

				flag = false;
				break;
			}
		}
		ans += flag;
	}

	printf("%d\n", ans);
}