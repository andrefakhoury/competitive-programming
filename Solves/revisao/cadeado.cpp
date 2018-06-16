#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100005
#define MAXM 100005

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> ini, fim;
int n, k, x;
int dp[20][20];

int diferenca (int x, int y) {
	if (dp[x][y] != -1) return dp[x][y];
	
	int ans = y-x;
	while (abs(ans) > 5) {
		if (ans < 0) ans+=10;
		else ans = 10-ans;
	}
	return dp[x][y] = ans;
}

int solve() {
	memset(dp, -1, sizeof(dp));
	int ans = 0, dif;
	for (int i = 0; i < n; i++) {
		dif = diferenca(ini[i]%10, fim[i]%10);
		//printf("(%d) %d -> %d (%d) : (%d)\n", i, ini[i], fim[i], dif, ans);
		ans += abs(dif);
		if (dif)
			for (int j = i; j < i+k; j++) {
				if (j >= n) return -1;
				ini[j] += dif; if (ini[j] < 0) ini[j] += 10;
			}
	}
	return ans;
}

int main () {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); ini.pb(x);
	}for (int i = 0; i < n; i++) {
		scanf("%d", &x); fim.pb(x);
	}
	printf("%d\n", solve());

	return 0;
}