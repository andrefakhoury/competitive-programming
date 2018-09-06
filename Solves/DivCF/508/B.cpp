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
#define MAXN 45005

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	int n; scanf("%d", &n);
	if (n <= 2) return !printf("No\n");

	for (int i = 2; i <= n; i++) {
		int total = (n*(n+1)/2)-i;
		if (__gcd(i, total) <= 1) continue;
		printf("Yes\n1 %d\n%d ", i, n-1);
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			printf("%d ", j);
		}
		return !printf("\n");
	}
	printf("No\n");

}