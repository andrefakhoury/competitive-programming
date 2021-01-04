#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const int MAXN = 3e4 + 5;

char s[MAXN];
int n;

struct Trie {
	map<char, int> m;
	Trie() { m.clear(); }
};

vector<Trie> all;

void add(int i, int j) {
	int p = 0;

	for (; i <= j; i++) {
		if (all[p].m.count(s[i])) {	
			p = all[p].m[s[i]];
		} else {
			all[p].m[s[i]] = all.size();
			p = all.size();

			all.emplace_back();
		}
	}
}

int search(int i) {
	int q = 0, p = 0;

	for (; i <= n; i++) {
		if (all[p].m.count(s[i])) {
			p = all[p].m[s[i]];
			q++;
		} else break;
	}

	return q;
}

int main() {

	int t; scanf("%d", &t);
	while(t--) {
		long long a, b;

		scanf("%d%lld%lld", &n, &a, &b);
		scanf(" %s", s+1);

		all.clear();
		all.emplace_back();

		long long ans = 0;

		for (int i = 1; i <= n; i++) {
			int q = search(i);

			if (a * q < b) ans += a;
			else {
				ans += b;
				i += q - 1;
			}

			for (int j = 1; j <= i; j++) {
				add(j, i);
			}
		}

		printf("%lld\n", ans);
	}

	return 0;
}