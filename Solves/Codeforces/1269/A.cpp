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

bool isPrime(ll n) {
	if (n == 1) return false;
	for (ll i = 2; i*i <= n; i++) if (n%i == 0) return false;
	return true;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n; cin >> n;
	for (ll i = 4; i <= 1e9; i++) {
		if (!isPrime(i) && !isPrime(i+n)) {
			cout << i+n << " " << i << '\n';
			break;
		}
	}



	return 0;
}