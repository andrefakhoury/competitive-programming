#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	int n, m; scanf("%d%d", &n, &m);

	int mex = 0x3f3f3f3f;
	while(m--) {
		int l, r; scanf("%d%d", &l, &r);
		mex = min(mex, r - l + 1);
	}

	printf("%d\n", mex);
	for (int i = 0; i < n; i++) printf("%d ", i % mex);
	printf("\n");

	return 0;
}