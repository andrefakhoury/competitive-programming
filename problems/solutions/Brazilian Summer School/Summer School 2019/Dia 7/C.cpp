#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

map<ll, bool> winner;
map<ll, ll> who;

bool solve(ll n) {
	if (winner.count(n)) return winner[n];
	
	int count = 0;
	for (ll i = 2; i * i <= n; i++) {
		if (n%i == 0) {
			count++;

			if (solve(i) == false) {
				who[n] = i;
				return winner[n] = true;
			} else if (solve(n/i) == false) {
				who[n] = n/i;
				return winner[n] = true;
			}
		}
	}

	if (count == 0) {
		who[n] = 0;
		return winner[n] = true;
	}

	return winner[n] = false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n; cin >> n;

	if (!solve(n)) cout << 2 << endl;
	else cout << "1\n" << who[n] << endl;

	return 0;
}