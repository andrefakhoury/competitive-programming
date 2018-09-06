#include <bits/stdc++.h>
using namespace std;

#define DEBGG(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(false);
#define vszz(v) ((int)v.size())
#define xx first
#define yy second

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
#define MAXN 50

typedef long long ll;
typedef pair<int, int> pii;

int v[MAXN];

int main () {
	int n, a, b; scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++) scanf("%d", v+i);

	//0 white 1 black 2 ainda

	ll ans = 0;
	for (int i = 1, j = n; i <= j; i++, j--) {
		if (i == j) {
			if (v[i] == 2) ans += min(a, b);
			break;
		}

		if (v[i] == v[j]) {
			if (v[i] == 2) ans += 2*min(a, b);
		} else {
			if (v[i] != 2 && v[j] != 2) return !printf("-1\n");
			if (v[i] == 2) {
				if (v[j] == 0) ans += a;
				else ans += b;
			} else if (v[j] == 2) {
				if (v[i] == 0) ans += a;
				else ans += b;			
			}
		}

	}

	printf("%lld\n", ans);

	return 0;
}