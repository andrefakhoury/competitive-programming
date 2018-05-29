#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define modulo 1000000007

using namespace std;

long long int dp[101][101][101];

long long int solve(int n1, int n2, int n3) {
	long long int ans = 0;
	
	if (n1 == 0 || n2 == 0 || n3 == 0) return 1;
	
	if (dp[n1][n2][n3] != 0) return dp[n1][n2][n3];
	
	if (n1 >= n2) ans += solve(n1-n2, n2, n3) % modulo;
	if (n1 >= n3) ans += solve(n1-n3, n2, n3) % modulo;
	if (n2 >= n1) ans += solve(n1, n2-n1, n3) % modulo;
	if (n2 >= n3) ans += solve(n1, n2-n3, n3) % modulo;
	if (n3 >= n1) ans += solve(n1, n2, n3-n1) % modulo;
	if (n3 >= n2) ans += solve(n1, n2, n3-n2) % modulo;
	
	dp[n1][n2][n3] = ans % modulo;
	
	return dp[n1][n2][n3];		
}


int main() {
	ios::sync_with_stdio(false);
	
	int n1, n2, n3;
	cin >> n1 >> n2 >> n3;
	
	cout << solve(n1, n2, n3);
	
	return 0;
}