#include <bits/stdc++.h>
using namespace std;

set<vector<int> > ans;
vector<int> v;

bool isPrime(int n) {
	for (int i = 2; i < n; i++)
		if (n % i == 0) return false;
	return true;
}

void solve(int cur, int last, int mask, int n) {
	if (!isPrime(cur + last)) return;
	mask |= 1 << cur;

	if (mask == (1 << (n + 1)) - 2 && isPrime(1 + cur)) {
		ans.insert(v);
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (mask & (1 << i)) continue;

		v.push_back(i);
		solve(i, cur, mask, n);
		v.pop_back();
	}
}

int main() {
	int n, cs = 1;

	while(~scanf("%d", &n)) {
		ans.clear();

		for (int i = 2; i <= n; i++) {
			v = {1, i};
			solve(i, 1, 2, n);
		}

		if (cs != 1) printf("\n");
		printf("Case %d:\n", cs++);

		if (n == 1) {
			printf("1");
			continue;
		}

		size_t qt = 0;
		for (auto& i : ans) {
			size_t qtt = 0;
			for (int j : i) {
				qtt++;
				printf("%d", j);
				if (qtt != i.size()) printf(" ");
			}
			if (qt != ans.size() - 1) printf("\n");
			qt++;
		}

		printf("\n");
	}
}