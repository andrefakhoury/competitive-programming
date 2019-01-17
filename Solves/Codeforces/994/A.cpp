#include <bits/stdc++.h>

using namespace std;
#define pb push_back

vector<int> seq, fin, ans;

int main() {
	int n, m, x; scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); seq.pb(x);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &x); fin.pb(x);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (seq[i] == fin[j]) {
				ans.pb(seq[i]); fin[j] = -1; break;
			}
		}
	}

	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}