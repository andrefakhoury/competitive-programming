#include <bits/stdc++.h>

#define pb push_back
#define fi first

using namespace std;
typedef long long ll;

const int N = 100007;
int l, k;

ll memo[N][2];

ll solve(int w, int black) {
	if(w == 0) return black;
	ll & st = memo[w][black];

	if(st == -1) {
		if(black) {
			st = 1;
			if(w) st += solve(w-1, 0);
		} else {
			st = solve(w-1, 1) + (k <= w ? solve(w - k, 1) : 0);
		}
	}
	return st;
}

int main() {
	memset(memo, -1, sizeof memo);
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> l >> k;

    ll ans = solve(l - 1, 1) + (k <= l? solve(l - k, 1) : 0);
    cout << ans << endl;
}