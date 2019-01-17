#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;

string s;
ll memo[200010][5];

ll solve(int i, int sum) {
	sum%=3;
	if (i == (int)s.size()) return 0;
	if (memo[i][sum] != -1) return memo[i][sum];
	
	int cur = s[i]-"0";

	if ((sum+cur)%3 == 0)
		return memo[i][sum] = solve(i+1, 0) + 1;
	else if (cur%3 == 0)
	    return memo[i][0] = solve(i+1, 0) + 1;

	return memo[i][sum] = max(solve(i+1, 0), solve(i+1, (sum+cur)%3));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(memo, -1, sizeof(memo));

	cin >> s;
	cout << solve(0, 0) << endl;
	return 0;
}