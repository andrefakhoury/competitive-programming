#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 500 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN];
int memo[MAXN][MAXN]; // memo[l][r] = tamanho minimo que fica dps de encolher
int elem[MAXN][MAXN]; // elem[l][r] = para qual elemento converge

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int l = 1; l <= n; l++) {
		for (int r = l; r <= n; r++) {
			if (l == r) elem[l][r] = a[l];
			memo[l][r] = r - l + 1;
		}
	}

	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			for (int k = l; k < r; k++) {
				memo[l][r] = min(memo[l][r], memo[l][k] + memo[k+1][r]);
				if (memo[l][k] == 1 && memo[k+1][r] == 1 && elem[l][k] == elem[k+1][r]) // converge
					memo[l][r] = 1, elem[l][r] = elem[l][k] + 1;
			}
		}
	}

	cout << memo[1][n] << '\n';
	return 0;
}