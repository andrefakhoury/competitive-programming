#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
//ios::sync_with_stdio(false);

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

typedef long long ll;
typedef pair<int, int> pii;

int n[1005];
map<int, int> occ;

int main () {
	int N; scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", n+i);
	}

	for (int i = 0; i < N; i++) {
		if (n[i]%2 == 0) n[i]--;

		printf("%d ", n[i]);
	} printf("\n");

	return 0;
}