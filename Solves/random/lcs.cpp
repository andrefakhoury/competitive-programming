#include <bits/stdc++.h>
using namespace std;

#define LEFT(x) 2*(x)
#define RIGHT(x) 2*(x)+1

const int MAXN = 10005;

int a[MAXN], b[MAXN];
int st[4*MAXN], dp[MAXN];
map<int, int> idx;

void update(int p, int l, int r, int i, int x) {
	if (l == r) st[p] = x;
	else {
		int mid = (l+r)/2;
		if (l <= i && i <= mid) update(LEFT(p), l, mid, i, x);
		else update(RIGHT(p), mid+1, r, i, x);
		st[p] = st[LEFT(p)] + st[RIGHT(p)];
	}
}

int query(int p, int l, int r, int a, int b) {
	if (a < l || b > r) return 0;
	if (a >= l && b <= r) return st[p];
	int mid = (l+r)/2;
	return query(LEFT(p), l, mid, a, b) + query(RIGHT(p), mid+1, r, a, b);
}


int LCS(int n) { //O(NlogN)
	for (int i = 1; i <= n; i++) idx[a[i]] = i;

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (idx.count(b[i])) {
			dp[i] = 1 + query(1, 1, n, 1, idx[b[i]] - 1);
			update(1, 1, n, idx[b[i]], dp[i]);
		}
		else dp[i] = 0;

		ans = max(ans, dp[i]);
	}

	return ans;
}

void solveLCS() {
	int n; scanf("%d", &n);
	char c;
	for (int i = 1; i <= n; i++) {
		scanf("%c", &c);
		a[i] = c-'a'+1;
	}
	for (int i = 1; i <= n; i++) {
		scanf("%c", &c);
		b[i] = c-'a'+1;
	}
	printf("%d\n", LCS(n));
}

int v[MAXN];
int LIS(int n) {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1 + query(1, 1, n, 1, v[i]-1);
		update(1, 1, n, v[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

void solveLIS() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", v+i);
	printf("%d\n", LIS(n));
}

int main() {
	solveLIS();
	// solveLCS();
	return 0;
}