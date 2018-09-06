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
#define MAXN 1005

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
vector<int> pos;
int ret;

int check() {
	int cnt = 0, first = -1;
	ret = INF;

	for (int i = 1; i <= k+1; i++) {
		cnt = 1;
		for (int j = i+2*k+1; j <= n; ) {
			cnt++;
			if (j+k >= n) {
				if (cnt < ret) {
					first = i;
					ret = cnt;
				}
				break;
			}
			j += 2*k+1;
		}
	}
	return first;
}

int main () {
	scanf("%d%d", &n, &k);

	int ans = -1;
	for (int i = 1; i <= n; i++) {
		if (i+(2*i*k) == n) {
			ans = i;
			break;
		}
	}

	if (k >= n) {
		printf("1\n1\n");
		return 0;
	}
	if (k >= n/2) {
		printf("1\n%d\n", (n+1)/2);
		return 0;
	}

	if (ans != -1) {
		printf("%d\n", ans);
		for (int i = 0; i < ans; i++) {
			printf("%d ", (2*i*k)+k+i+1);
		}
		printf("\n");
		return 0;
	}

	int first = check();
	printf("%d\n", ret);
	for (int i = first, count = 0; count < ret; i+=2*k+1, count++) {
		if (i > n) i = n;
		printf("%d ", i);
	} printf("\n");

	return 0;
}