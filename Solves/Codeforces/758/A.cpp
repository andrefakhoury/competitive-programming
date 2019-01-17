#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1000005;

int main() {
	int n; cin >> n;
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> b[i];
	int maxi = 0;
	for (int i = 0; i < n; i++) maxi = max(maxi, b[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) ans += maxi - b[i];
	cout << ans << endl;
}
