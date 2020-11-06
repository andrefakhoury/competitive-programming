#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;

int price[101];
int value[101];
int idx[101][12];
int memo[101][23][1200];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n, x, t, k;
	while(cin >> n >> x >> t >> k, n || x || t || k) {
		n++;

		for (int i = 0; i < k; i++) {
			cin >> price[i];
			value[i] = 0;
			for (int j = 0; j < n; j++) {
				cin >> idx[i][j];
				value[i] += idx[i][j];
			}
			cout << value[i] << endl;
		}

		mset(memo[k], 0);
		for (int i = k - 1; i >= 0; i--) {
			for (int qt = 0; qt <= 2 * n; qt++) {
				for (int pr = 0; pr <= x * n; pr++) {
					memo[i][qt][pr] = memo[i+1][qt][pr];
					auto best = [&](int next) { memo[i][qt][pr] = max(memo[i][qt][pr], next); };
					auto get = [](int x) { return x + (x + 9) / 10; };
					auto can = [&](int prc) { return get(prc + t * n) <= n * x; };

					// pega 1
					if (can(pr + price[i]) && qt + 1 <= 2 * n)
						best(value[i] + memo[i + 1][qt + 1][pr + price[i]]);

					// pega 2
					if (can(pr + 2 * price[i]) && qt + 2 <= 2 * n)
						best(2 * value[i] + memo[i + 1][qt + 2][pr + 2 * price[i]]);
				}
			}
		}

		cout << fixed << setprecision(2) << 1.0 * memo[0][0][0] / n << "\n";
	}
}