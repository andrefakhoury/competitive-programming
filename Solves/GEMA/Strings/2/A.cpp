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
	int n = (int)s.length();
	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j]) j = pi[j-1];
		if (s[i] == s[j]) j++;
		pi[i] = j;
	}

	return pi;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		string s; cin >> s;
		ll k; cin >> k;
		ll n = s.size();

		vector<int> pi = prefixFunction(s);

		ll j = pi[n-1];
		cout << n + (n - j) * (k - 1) << '\n';
	}
}