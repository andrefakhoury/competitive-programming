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
const int MAXN = 2e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline void _solve() {
	int n, m; cin >> n >> m;
	cout << (n%m == 0 ? "YES" : "NO") << '\n';

}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T = 1;
	cin >> T;
	while(T--) _solve();
	return 0;
}