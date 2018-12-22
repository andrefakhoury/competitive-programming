#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005;

#define MOD 1000000007LL

string s;

int memo[MAXN];

int solve(int i) {
	if (i >= s.size()) return 0;
	if (memo[i] != -1) return memo[i];

	if (s[i] == 'b' && bmid == 0) return memo[i] = solve(i+1, 0)%MOD;
	if (s[i] == 'b') return memo[i] = solve(i+1, 2)%MOD;
	if (s[i] != 'a') return memo[i] = solve(i+1, bmid)%MOD;

	memo[i] = 0;

	bool podeUsar = false;
	for (int at = i+1; at < s.size(); at++) {
		if (s[at] == 'b') podeUsar = true;
		if (s[at] != 'a') continue;
		if (podeUsar) memo[i]++;
	}

	memo[i]

	memo[i] = 1;

	if (bmid == 2) memo[i] = (memo[i] + 1 + solve(i+1, 2))%MOD;
	else memo[i] = (memo[i] + solve(i+1, 1))%MOD;
	return memo[i]%MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	memset(memo, -1, sizeof(memo));

	cin >> s;

	cout << (solve(0, 0))%MOD << endl;
	return 0;
}