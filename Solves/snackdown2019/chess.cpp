#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 105;
typedef long long ll;

int n, m, x, y;

bool inbituin(int x, int i1, int i2) {
	if ((x < i1 && x < i2) || (x > i1 && x > i2)) return false;
	return true;
}

int main() {
	int t; scanf("%d", &t);

	while(t--) {
		scanf("%d%d%d%d", &n, &m, &x, &y);
		ll ans = 0;
		for (int i1 = 1; i1 <= n; i1++) {
			for (int j1 = 1; j1 <= m; j1++) {
				for (int i2 = 1; i2 <= n; i2++) {
					for (int j2 = 1; j2 <= m; j2++) {
						if (i1 == i2 && j1 == j2) continue;
						if (i1 == x && j1 == y) continue;
						if (i2 == x && j2 == y) continue;

						ans++;
						if (i1 == i2) {
							if (!inbituin(y, j1, j2)) ans--;
						} else if (j1 == j2) {
							if (!inbituin(x, i1, i2)) ans--;
						} else if (__gcd(i1, i2) != 1 && __gcd(j1, j2) != 1) {
							if ()
						}

					}
				}
			}
		}
		printf("%lld\n", ans);


	}

	return 0;
}