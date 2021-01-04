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

bool isPrime(ll x) {
	if (x == 1) return false;
	for (ll i = 2; i*i <= x; i++)
		if (x%i == 0) return false;
	return true;
}

int main() {
	int n; scanf("%d", &n);
	while(n--) {
		ll x; scanf("%lld", &x);
		x++;
		if (x%2 == 1 && x%7 == 0 && isPrime(x+2))
			printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}