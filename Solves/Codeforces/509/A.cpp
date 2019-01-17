#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n; cin >> n;
	int m[n+1][n+1];
	
	for (int i = 1; i <= n; i++) m[i][1] = 1;
	for (int i = 1; i <= n; i++) m[1][i] = 1;

	for (int i = 2; i <= n; i++)
		for (int j = 2; j <= n; j++)
			m[i][j] = m[i-1][j] + m[i][j-1];

	int ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			ans = max(ans, m[i][j]);

	cout << ans << endl;	
	return 0;
}