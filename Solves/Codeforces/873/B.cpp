#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

map<int, int> id, cur, sum;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;
	s = "X" + s;

	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1];
		if (s[i] == '1') sum[i]++;
		else sum[i]--;

		id[sum[i]] = i;
	}

	int ans = id[0];
	for (int i = 1; i <= n; i++) {
		cur[i] = cur[i-1];
		if (s[i] == '1') cur[i]++;
		else cur[i]--;

		ans = max(ans, id[cur[i]] - i);
	}

	cout << ans << endl;


}