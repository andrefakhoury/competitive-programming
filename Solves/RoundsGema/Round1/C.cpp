#include <bits/stdc++.h>

using namespace std;

int dp[14][14][14];

int solve(int n1, int n2, int n3) {
	if (dp[n1][n2][n3] != 0) return dp[n1][n2][n3];
	if (!n1 || !n2 || !n3) return 1;
	int ans = 0;
	
	if (n1 >= n2) ans += solve(n1-n2, n2, n3);
	if (n1 >= n3) ans += solve(n1-n3, n2, n3);
	if (n2 >= n1) ans += solve(n1, n2-n1, n3);
	if (n2 >= n3) ans += solve(n1, n2-n3, n3);
	if (n3 >= n1) ans += solve(n1, n2, n3-n1);
	if (n3 >= n2) ans += solve(n1, n2, n3-n2);
	
	return ans;
}

int main() {
	ios :: sync_with_stdio(false);
	
	int N1, N2, N3;
	cin >> N1 >> N2 >> N3;
	
	cout << solve(N1, N2, N3) << endl;
	
	return 0;
}