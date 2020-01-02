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
	int n, k1, k2; cin >> n >> k1 >> k2;
	vector<int> v1(k1), v2(k2);

	for (int i = 0; i < k1; i++) cin >> v1[i];
	for (int i = 0; i < k2; i++) cin >> v2[i];

	bool flag = false;
	for (int i = 0; i < k1; i++) {
		if (v1[i] == n) flag = true;
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";


}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();


	

	return 0;
}