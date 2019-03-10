#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010, INF = 1e5;

int n, k;
int a[MAXN], freq[10 * MAXN];
int memo[MAXN][MAXN], first[10 * MAXN];

int solve(int i, int curTeams) {
	if (curTeams > k) return -INF;
	if (i > n) {
		if (curTeams == 0) return -INF;
		return 0;
	}

	if (memo[i][curTeams] != -1) return memo[i][curTeams];
	
	int qtd = 0;
	for (int j = 0; j <= 5; j++) qtd += freq[a[i] + j];

	return memo[i][curTeams] = max(qtd + solve(first[a[i]+6], curTeams + 1), solve(i+1, curTeams));
}

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	sort(a+1, a+n+1);
	
	//compress
	int cur = 1, last = a[1];
	a[1] = cur;
	for (int i = 2; i <= n; i++) {
		if (a[i]-last <= 5) cur += a[i] - last;
		else cur += 6;

		last = a[i];
		a[i] = cur;
	}

	for (int i = n; i >= 1; i--) first[a[i]] = i;
	for (int i = cur; i >= 1; i--) first[cur] = first[cur] == 0 ? first[cur+1] : first[cur];
	for (int i = 1; i <= n; i++) freq[a[i]]++;

	memset(memo, -1, sizeof memo);
	printf("%d\n", solve(1, 0));	
}