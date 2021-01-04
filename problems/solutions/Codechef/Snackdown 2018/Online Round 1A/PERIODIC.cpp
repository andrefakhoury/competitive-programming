#include <bits/stdc++.h>
using namespace std;

const int MAXN  = 100005;

int a[MAXN], b[MAXN], n;

int proximo(int v, int k) {
	return v+1 > k ? 1 : v+1;
}

bool check(int k) {
	bool fa = false;
	int prev = -1;

	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) { 
			if (fa) prev = proximo(prev, k);
		} else {
			if (!fa) fa = true;
			else {
				if (a[i] == 1) {
					if (prev == 1 && k != 1) return false;
					
					if (prev != k) return false;
				}

				if (a[i] != proximo(prev, k)) return false;
			}
			prev = a[i];
		}
	}
	return true;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		memset(a, 0, sizeof (a));
		bool imp = false;

		int maxi = -1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a+i);
			maxi = max(maxi, a[i]);
		}

		int ans = 0;

		for (int i = maxi; i <= maxi+n+1; i++)
			if (check(i)) ans = i;

		if (ans == 0 || imp) printf("impossible\n");
		else if (ans > maxi+n) printf("inf\n");
		else printf("%d\n", ans);
	}

	return 0;
}