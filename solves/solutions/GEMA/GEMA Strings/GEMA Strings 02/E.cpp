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

vector<int> prefixFunction(vector<int>& s) {
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

vector<int> build_Z(vector<int>& s) {
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
	int n; cin >> n;
	vector<int> pi(n);
	for (int i = 0; i < n; i++) cin >> pi[i];

	vector<int> s = {1};
	for (int i = 1, l = 1; i < n; i++) {
		if (pi[i]) s.push_back(s[pi[i]-1]);
		else s.push_back(++l);
	}

	vector<int> z = build_Z(s);
	for (int i : z) cout << i << ' ';
	cout << '\n';
}