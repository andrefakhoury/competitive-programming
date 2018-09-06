#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 200010
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

map<string, int> dp;

int solve(string& s) {
	int soma = 0, ans = 0;
	if (dp[s]) return dp[s];
	for (int i = 0; i < s.size(); i++) {
		soma += s[i]-'0';
		if (soma%3 == 0 || !soma) {
			soma = 0;
			ans++;
		}
	}
	return dp[s] = ans;
}

int main () {
	ios::sync_with_stdio(false);

	string s, aux; cin >> s;

	int ans = solve(s);
	for (int i = 0; i < s.size(); i++) {
		aux = s; aux.erase(i, 1);
		ans = max(ans, solve(aux));
	}

	cout << ans << endl;

}