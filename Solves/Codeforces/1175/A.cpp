#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

ll solve(ll n, ll k) {
	if (n == 0) return 0;
	if (n < k) return n;

	if (n%k == 0) return 1 + solve(n/k, k);
	return n%k + solve(n - n%k, k);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		ll n, k; cin >> n >> k;
		cout << solve(n, k) << '\n';
	}
	
	return 0;
}