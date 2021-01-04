#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN];
string s;
int n, m;
ll memo[MAXN][2];

ll solve(int i, int x) {
	if (i == m) return x;
	if (~memo[i][x]) return memo[i][x];

	for (int d = 0; d <= 9; d++) {
		
	}


	if (x) return memo[i][x] = min({a[i] + solve(i+1, x), 10 - a[i] + solve(i+1, x), 1 + a[i] + solve(i+1, 0)});
	return memo[i][x] = min({a[i] + solve(i+1, 0), 10 - a[i] + 1 + solve(i+1, 1)});
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	n = s.size();
	for (int i = 0; i < n; i++) a[i] = s[i] - '0';

	m = n;
	while(!a[m-1]) m--;

	memset(memo, -1, sizeof memo);
	cout << solve(0, 0) << '\n';



	return 0;
}