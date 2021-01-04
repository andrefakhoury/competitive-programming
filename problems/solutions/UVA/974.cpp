#include <bits/stdc++.h>
using namespace std;

const int MAXN = 4e4 + 4;

bool isk[MAXN];

int num(string& s, int i, int j) {
	int cur = 0;
	
	while (i <= j) {
		cur = cur * 10 + s[i] - '0';
		i++;
	}

	return cur;
}

bool isKaprekar(int n) {
	string s = to_string(n * n);

	int j = (int)s.size() - 1;
	for (int i = 0; i < j; i++) {
		int l = num(s, 0, i);
		int r = num(s, i+1, j);

		if (l && r && l + r == n)
			return true;
	}

	return false;
}

void pre() {
	for (int i = 2; i < MAXN; i++) isk[i] = isKaprekar(i);
}

int main() {
	pre();
	int q; scanf("%d", &q);

	for (int cs = 1; cs <= q; cs++) {
		int l, r; scanf("%d%d", &l, &r);
		l--; vector<int> ans;

		if (cs != 1) printf("\n");
		printf("case #%d\n", cs);

		while(++l <= r) if (isk[l]) ans.push_back(l);

		if (!ans.size()) printf("no kaprekar numbers");
		else for (int i = 0; i < (int)ans.size(); i++) {
			printf("%d", ans[i]);
			if (i != ans.size() - 1) printf("\n");
		}

		printf("\n");
	}
}