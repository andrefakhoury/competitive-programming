#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

int a[MAXN];
int ans[MAXN];
int n;

int memo[MAXN][3];

bool solve(int i, int w) {
	if (memo[i][w] != -1) return memo[i][w];

	if (i > n) return true;

	if (i == n) {
		ans[i] = w;
		return true;
	}

	if (w == 0 && a[i+1] <= a[i]) {
		if (solve(i+1, !w))
			ans[i] = w;
		else return false;
	} else if (w == 0 && a[i] > a[i]) {
		if (solve(i+1, w)) {
			ans[i] = w;
			return true;
		} else {
			if (solve(i+1, !w)) {
				ans[i] = w;
				return true;
			} else {
				return false;
			}
		}
	}


	if (w == 1 && a[i+1] >= a[i]) {
		if (solve(i+1, !w))
			ans[i] = w;
		else return false;
	} else if (w == 1 && a[i] < a[i]) {
		if (solve(i+1, w)) {
			ans[i] = w;
			return true;
		} else {
			if (solve(i+1, !w)) {
				ans[i] = w;
				return true;
			} else {
				return false;
			}
		}
	}

}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);

	memset(memo, -1, sizeof memo);

	if (solve(1, 0)) {
		printf("YES\n");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
	} else if (solve(1, 1)) {
		printf("YES\n");
		for (int i = 1; i <= n; i++) printf("%d ", ans[i]);		
	} else {
		printf("NO\n");
	}	

}