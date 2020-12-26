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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		string s; cin >> s;
		int n = s.size();

		string t = s;
		reverse(t.begin(), t.end());

		string k = s + "#" + t;
		vector<int> pi = prefixFunction(k);

		int sz = 0;
		for (int i = n+1; i < 2*n+1; i++) {
			sz = max(sz, pi[i]);
		}

		string ans = s.substr(0, sz);
		reverse(ans.begin(), ans.end());
		cout << ans;
		cout << '\n';
	}
}