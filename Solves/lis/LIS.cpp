#include <bits/stdc++.h>
using namespace std;

#define MAXN 100005

int n;
int v[MAXN], dp[MAXN];

//n2
int itLis() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if (v[i] > v[j]) dp[i] = max(dp[i], dp[j]+1);
		ans = max(ans, dp[i]);
	}
	return ans;
}

int stLis() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = 1 + query(1, v[i]-1); 	//se tivesse um vetor pra pegar as lis com o melhor custo, trocava o "1 +" por "c[i] +"
										//se tivesse longest decreasing subsequence : 1+query(v[i], MAXN);
										//se tivesse longest not decreasing subsequence : 1+ query(1, v[i]);
		update(v[i], dp[i]);
		ans = max(ans, dp[i]);
	}
	return ans;
}

void compressaoCoords() {
	//coloca tudo os elementos num vector<int> v;
	//e dps coloca os elementos comprimidos num int a[MAXN]

	//pra limpar tudo
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());

	for (int i = 1; i <= n; i++) a[i] = lower_bound(v.begin(), v.end(), a[i]);
}

int LCS() {
	map<int, int> idx;
	int a[MAXN], b[MAXN];

	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	for (int i = 1; i <= n; i++) scanf("%d", b+i);

	for (int i = 1; i <= n; i++) idx[a[i]] = i;

	for (int i = 1; i <= n; i++) {
		if (idx.count(b[i])) {
			dp[i] = 1 + query(1, 1, n, 1, idx[b[i]] - 1);
			update(1, 1, n, idx[b[i]], dp[i]);
		} else dp[i] = 0;
	}
}

int kadane() {
	//maior soma ate o elemento
	ll ans = 0;

	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i-1] + a[i], a[i]);
		ans = max(ans, dp[i]);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", v+i);

	printf("%d\n", lis());
	return 0;
}
