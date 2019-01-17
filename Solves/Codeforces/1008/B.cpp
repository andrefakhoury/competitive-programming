#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100005
#define MAXM 100000
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int paral[3], qt[3];

int main () {
	int n; scanf("%d", &n);
	int prev = inf, x, y, mini, maxi, deu = 1;
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &x, &y);
		mini = min(x, y);
		maxi = max(x, y);
		if (maxi <= prev) {
			prev = maxi;
		} else if (mini <= prev) {
			prev = mini;
		} else {
			deu = 0;
		}
	}
	if (deu) 
		return !printf("YES\n");
	else
		return !printf("NO\n");
}	