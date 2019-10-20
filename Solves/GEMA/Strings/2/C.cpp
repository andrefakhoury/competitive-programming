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

int prefixFunction(string& s, int k) {
	int n = s.size(), ans = 0;
	vector<int> pi(n);

	for (int i = 1; i < n; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 && s[pi[i]] != s[i])
			pi[i] = pi[pi[i]-1];
		if (s[i] == s[pi[i]]) pi[i]++;

		if (pi[i] == k) ans++;
	}

	return ans;
}

bool test(string& p, string& t, string& A, vector<int>& B, int k, int n) {
	string s = p;
	for (char& c : s) c = A[(B[c] + k) % n];
	s += "$" + t;
	return prefixFunction(s, p.size()) == 1;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		string A, p, t; cin >> A >> p >> t;
		vector<int> B(128);

		for (int i = 0; i < (int)A.size(); i++) B[A[i]] = i;

		vector<int> ans;
		for (int i = 0; i < (int)A.size(); i++)
			if (test(p, t, A, B, i, A.size())) ans.pb(i);

		if (ans.empty()) cout << "no solution";
		else if (ans.size() == 1u) {
			cout << "unique: " << ans[0];
		} else {
			cout << "ambiguous: ";
			for (int i = 0; i < (int)ans.size(); i++)
				cout << ans[i] << (i == (int)ans.size() - 1 ? "" : " ");
		}

		cout << "\n";
	}
}