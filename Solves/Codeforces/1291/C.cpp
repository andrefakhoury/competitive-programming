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
const int MAXN = 3500 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int convince(int i, int n, int m, int k, vector<int>& a, vector<int> cur) {
	if (i == m) {
		deque<int> dq;
		for (int x : a) dq.push_back(x);

		for (int x : cur) {
			
		}

	}

}


inline void _solve() {
	int n, m, k; cin >> n >> m >> k;
	vector<int> a(n);
	for (int& i : a) cin >> i;

	for (int i = 0; i < m; i++) {


	}


	cout << solve(m, k, 0, n-1, a) << '\n';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) _solve();
	return 0;
}