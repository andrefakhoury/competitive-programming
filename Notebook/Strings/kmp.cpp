#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

char s[MAXN];



int main() {
	scanf(" %s", s);
	int n = strlen(s);

	vector<int> pi(n);
	for (int i = 1; i < n; i++) {
		pi[i] = pi[i-1];
		while(pi[i] > 0 && s[pi[i]] != s[i])
			pi[i] = pi[pi[i]-1];
		if (s[i] == s[pi[i]]) pi[i]++;
	}

	return 0;
}