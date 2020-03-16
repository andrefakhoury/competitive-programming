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
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) {
		ll n, k; cin >> n >> k;

		ll pot = 1, s = 0;
		while(pot <= 10000000000000000ll) pot *= k, s++;

		vector<int> used;
		for (int i = 1; i <= n; i++) {
			ll x; cin >> x;
			ll curPot = pot, curPow = s;
			for (ll curPot = pot, curPow = s; x; curPow--, curPot /= k) {
				while (x >= curPot) {
					x -= curPot;
					used.eb(curPow);
				}
			}
		}

		sort(used.begin(), used.end());

		bool ans = true;
		for (int i = 1; i < (int)used.size(); i++) ans &= used[i] != used[i-1];
		
		cout << (ans ? "YES" : "NO") << '\n';
	}


	return 0;
}