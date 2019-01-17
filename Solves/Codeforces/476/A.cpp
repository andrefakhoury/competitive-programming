#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n, m; cin >> n >> m;
	int ans = -1;

	for (int i = n; i >= (n+1)/2; i--)
		ans = i%m == 0 ? i : ans;

	cout << ans << endl;
	return 0;
}