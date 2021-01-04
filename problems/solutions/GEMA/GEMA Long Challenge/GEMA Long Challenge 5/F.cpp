#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e6 + 5;

int a[MAXN];

int main() {
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	sort(a+1, a+n+1);
	
	int ans = 0;
	for (int i = 1; i < MAXN; i++) {

		int l = 1;
		for (int j = i; l <= n && j < MAXN; j += i) {
			if (a[l] - k <= j && a[l] >= j) {
				l = upper_bound(a+1, a+n+1, j + k) - a;
			}
		}

		if (l > n) ans = i;
	}

	printf("%d\n", ans);
}