#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN], pos[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]] = i;
	}

	int cur = 0, ans = 0;
	for (int i = 1; i <= n; i++) {
		if (pos[i] > pos[i-1]) cur++;
		else cur = 0;

		ans = max(ans, cur);
	}

	cout << n - ans << endl;
}