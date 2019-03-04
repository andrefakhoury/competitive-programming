#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 123;

int p[MAXN], s[MAXN], b[MAXN];

int main() {
	int n, m, k; cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) cin >> p[i];
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) b[s[i]] = max(b[s[i]], p[i]);

	int ans = 0;
	for (int i = 1; i <= k; i++) {
		int c; cin >> c;
		if (p[c] < b[s[c]]) ans++;
	}

	cout << ans << endl;
}