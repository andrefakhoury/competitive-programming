#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

// j [1..n]
// se x_i for maior que j, pos == x_i
// se x_i for igual que j, pos == 1
// se x_i for menor que j, pos == x_i + 1

/**

> > ---- x_i+1 - x_i
> = ---- x_i - 1
> < ---- x_i+1 - x_i - 1
< = ---- x_i
< < ---- x_i+1 - x_i
**/

const int MAXN = 2e5 + 5;

int x[MAXN], ans[MAXN];
long long acc[MAXN];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i++) cin >> x[i];

	for (int i = 1; i < m; i++) {
		int j = max(x[i], x[i+1]);
		int k = min(x[i], x[i+1]);

		if (j == k) continue;

		acc[j+1] += j - k;

		acc[k] += j - 1;
		acc[k+1] -= j - 1;

		acc[k+1] += j - k - 1;
		acc[j] -= j - k - 1;

		acc[j] += k;
		acc[j+1] -= k;

		acc[1] += j - k;
		acc[k] -= j - k;
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += acc[i];
		cout << ans << ' ';
	}

	cout << '\n';
	return 0;
}