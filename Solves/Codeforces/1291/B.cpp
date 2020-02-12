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
const int MAXN = 3e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a[MAXN];

inline void _solve() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	a[0] = 0;
	a[n+1] = 0;

	int maxil = 0;
	int maxir = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] >= i - 1) {
			maxil = i;
		} else {
			break;
		}
	}

	for (int i = n; i >= 1; i--) {
		if (a[i] >= n - i) {
			maxir = i;
		} else {
			break;
		}
	}
	if (maxil == n || maxir == 1 || maxil >= maxir) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();

	return 0;
}