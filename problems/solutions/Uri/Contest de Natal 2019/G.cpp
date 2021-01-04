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
const int MAXN = 1e4 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		ll p1 = 0, p2 = 0;
		for (int i = 0; i < 3; i++) {
			ll x, d; scanf("%lld%lld", &x, &d);
			p1 += x*d;
		}
		for (int i = 0; i < 3; i++) {
			ll x, d; scanf("%lld%lld", &x, &d);
			p2 += x*d;
		}

		if (p1 > p2) printf("JOAO\n");
		else printf("MARIA\n");

	}
}