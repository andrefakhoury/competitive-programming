#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30010;
int a[MAXN], vis[MAXN];

int main() {
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n-1; i++) cin >> a[i];
	for (int i = 1; i <= n; i += max(a[i], 1)) vis[i] = 1;

	cout << (vis[k] ? "YES" : "NO") << endl;
	return 0;
}