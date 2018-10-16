#include <bits/stdc++.h>
using namespace std;

#define DEBGG(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(false);
#define SZOF(v) ((int)v.size())
#define xx first
#define yy second

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
#define MAXN 1005

typedef long long ll;
typedef pair<int, int> pii;

int sw[MAXN];

int main() {
	int n, r; scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i++) {
		scanf("%d", sw+i);
		if (sw[i] == 1) {
			sw[i] = 2;
		}
	}

	int ult = -1, st = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		sw[i] = 1;
		st--;
		if (sw[i] == 2) {
			if (st <= 0) {
				ans++;
				st = r-1;
				ult = -1;
			} else {
				ult = i;
			}

		}
		if (st < -(r-1) && ult == -1) return !printf("-1\n");
		else if (st < -(r+1)) {
			i = ult;
			st = 0;
		}
	}

	for (int i = 1; i <= n; i++) if (sw[i] == 0) return !printf("-1\n");

	printf("%d\n", ans);

	return 0;
}