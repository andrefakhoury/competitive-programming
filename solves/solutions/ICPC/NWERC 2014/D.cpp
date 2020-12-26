#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 5e5 + 5;
const int inf = 0x3f3f3f3f;

int g[maxn];
ll dp[maxn];
int l[maxn], r[maxn];
char ini[maxn];

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n;
	int m;

	cin >> n >> m;

	for (int i = 1; i <= m; i++) {
		cin >> ini[i] >> l[i] >> r[i];

		g[l[i]]++;
		g[r[i]]++;
	}

	vector<int> zero;

	for (int i = 1; i <= m; i++) if (g[i] == 0) zero.push_back(i);

	dp[zero[0]] = n;

	for (int i = 0; i < m; i++) {
		int at = zero[i];

		ll gl, gr;
		if (ini[at] == 'L') gl = (dp[at]+1)/2;
		else gl = dp[at]/2;

		gr = dp[at]-gl;

		if (l[at] != 0) {
			dp[l[at]] += gl;
			g[l[at]]--;

			if (g[l[at]] == 0) zero.push_back(l[at]);
		}

		if (r[at] != 0) {
			dp[r[at]] += gr;
			g[r[at]]--;

			if (g[r[at]] == 0) zero.push_back(r[at]);
		}
	}

	for (int i = 1; i <= m; i++) {
		if (dp[i]&1) {
			if (ini[i] == 'L') cout << "R";
			else cout << "L";
		}
		else cout << ini[i];
	}
	cout << "\n";

	return 0;
}