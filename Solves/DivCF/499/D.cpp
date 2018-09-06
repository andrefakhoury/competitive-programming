#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f

#define MAXN 1005

typedef long long ll;
typedef pair<int, int> pii;

bool verd[60];

int main () {
	int x, y;

	int r, n; scanf("%d%d", &r, &n);
	int l = 0, mid=(l+r)/2;

	for (int i = 0; i < n; i++) {
		printf("1\n"); fflush(stdout);
		scanf("%d", &y);
		if (y == 1) verd[i] = false;
		else if (y == -1) verd[i] = true;
		else return 0;
	}

	int vagao = 0;
	while(l < r) {
		mid = (l+r)/2;

		printf("%d\n", mid); fflush(stdout);
		scanf("%d", &y);

		if(!verd[vagao]) y*=-1;

		if (y == 0) return 0;
		if (y == 1) r = mid-1;
		else 		l = mid+1;

		vagao = (vagao+1)%n;
	}
	printf("%d\n", l); fflush(stdout);
	scanf("%d", &y);
	return 0;
}