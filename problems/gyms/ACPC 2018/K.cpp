#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int n, k, l, r;
const int M = 1000000007;

int memo[150][150][150][3];


// quantos antes de p
inline ll before(int x, int p) {
	return p / 3 + (p%3 >= x);
}

inline ll calc(int x) {
	return before(x, r) - (l == 0? 0 : before(x, l-1) );
}

stack<tuple<int, int, int, int> > visitou;
ll solve(int n0, int n1, int n2, int last) {
	if(n1 < 0 or n2 < 0 or n0 < 0) return 0;
	if(n1 + n2 + n0 == 0) return 1;

	int & st = memo[n0][n1][n2][last];
	if(st == -1) {
		visitou.emplace(n0, n1, n2, last);

		st = 0;
		// testa botar os 3
		for(int x = 0; x <= 2; x++) {
			int prox = (last + x);
			if(prox >= 3) prox -= 3;

			// quantos %3 == x de l a r

			st = (st + calc(x) * solve(n0 - (prox == 0), n1 - (prox == 1), n2 - (prox == 2), prox) % M ) % M;
		}
	}
	return st;
}

void _solve() {
	cin >> n >> k >> l >> r;

	k = 2 * k;

	ll ans = 0;
	for(int n0 = 0; n0 * n0 - 200 <= k; ++n0) {
		for(int n1 = 0; n1 * n1 - 200 <= k; ++n1) {
			for(int n2 = 0; n2 * n2 - 200 <= k; ++n2) {
				if(n0 * n0 + n1 * n1 + n2 * n2 + n0 - n1 - n2 == k and n1 + n2 + n0 == n) {
					ans += solve(n0, n1, n2, 0);
					ans %= M;
				}
			}
		}
	}

	// libera a memoria
	while(visitou.size()) {
		int i, j, k, last;
		tie(i, j, k, last) = visitou.top();
		visitou.pop();
		memo[i][j][k][last] = -1;
	}

	cout << ans << '\n';
}
int main() {
	freopen("khoshaf.in", "r", stdin);
	memset(memo, -1, sizeof memo);
	ios::sync_with_stdio(0); cin.tie(0);

	int t; cin >> t;

	while(t--) {
		_solve();
	}
}