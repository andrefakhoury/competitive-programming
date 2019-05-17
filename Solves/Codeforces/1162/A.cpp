#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int maxi[500];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, h, m; cin >> n >> h >> m;

	for (int i = 1; i <= n; i++) maxi[i] = h;

	for (int i = 1; i <= m; i++) {
		int l, r, x; cin >> l >> r >> x;
		for (int j = l; j <= r; j++) maxi[j] = min(maxi[j], x);
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += maxi[i] * maxi[i];
	}

	cout << ans << endl;
}