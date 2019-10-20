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

vector<int> build_Z(string& s) {
	int n = s.size();
	vector<int> z(n, 0);

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);

		while(i + z[i] < n && s[z[i]+i] == s[z[i]])
			z[i]++;

		if (z[i] + i - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	return z;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);


	string s; cin >> s;

	vector<int> pf = prefixFunction(s);
	vector<int> z  = build_Z(s);

	int n = s.size();
	vector<int> pf2(n);
	for (int i = 0; i < n; i++) {
		if (z[i]) {
			pf2[i + z[i] - 1] = max(pf2[i + z[i] - 1], z[i]);
		}
	}
	int cur = 0;
	for (int i = n-1; i >= 0; i--) {
		if (cur > 1 && cur > pf2[i]) pf2[i] = --cur;
		if (pf2[i]) cur = pf2[i];
	}

	for (int i = 0; i < n; i++) {
		if (pf[i] != pf2[i]) {
			cout << "Diferenca em " << i << endl;
			cout << pf[i] << " vs " << pf2[i] << endl;

			for (int j = 440; j < pf.size(); j++) cout << pf[j] << ' ';
			cout << endl;
			

			for (int j = 440; j < pf.size(); j++) cout << pf2[j] << ' ';
			cout << endl;

			exit(1);
		}
	}
}