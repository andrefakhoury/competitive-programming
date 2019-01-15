#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100000, INF = 0x3f3f3f3f;

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);
	
	int n; scanf("%d", &n);

	int x = ceil(sqrt(n));

	for (ll y = 1; y <= x; y++) {
		if (x*y >= n) return !printf("%lld\n", x+y);
	}

	return 0;
}