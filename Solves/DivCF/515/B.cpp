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
	map<int, int> pos;
	for (int i = 1; i <= n; i++) {
		scanf("%d", sw+i);
		if (sw[i] == 1) {
			sw[i] = 2;
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int flag1 = 0;
		int flag2 = 0;

		if (sw[i] == 2) {
			ans++;

			for (int j = i-r+1; j < i; j++) {
				if (j < 1) continue;
				if (sw[j] == 2) flag1 = 1;
				if (sw[j] != 2) sw[j] = 1;
			}

			for (int j = i+1; j <= i+r-1; j++) {
				if (j > n) continue;
				if (sw[j] == 2) flag2 = 1;
				if (sw[j] != 2) sw[j] = 1;
			}

			if (flag1 && flag2) ans--;
		}
	}

	for (int i = 1; i <= n; i++) {
		//printf("%d ", sw[i]);
		if (sw[i] == 0) return !printf("-1\n");
	} //printf("\n");
	printf("%d\n", ans);

	return 0;
}