#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

vector<int> prefixFunction(string& s) {
	int n = s.size();
	vector<int> pi(n);

	for (int i = 1; i < n; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 && s[pi[i]] != s[i])
			pi[i] = pi[pi[i]-1];
		if (s[i] == s[pi[i]]) pi[i]++;
	}

	return pi;
}

string memo[105][105];

int solve(int i, int j, int q, int n, int m, string& s, string& t) {
	for ()

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s, t, x; cin >> s >> t >> x;

	int n = s.size(), m = t.size(), k = x.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
				
			if (i == 0 && j == 0) memo[i][j] = string();
			else if (s[i-1] == t[j-1]) memo[i][j] = memo[i-1][j-1] + s[i-1];
			else memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
		}
	}

	cout << memo[n][m] << endl;
}