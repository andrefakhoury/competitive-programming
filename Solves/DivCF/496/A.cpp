#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main () {
	int n, x, cont = 1, last; scanf("%d", &n);
	vector<int> stair;
	scanf("%d", &last);
	for (int i = 1; i < n; i++) {
		scanf("%d", &x);
		if (x != last+1) {
			cont++;
			stair.pb(last);
		}
		last = x;
	} stair.pb(last);

	printf("%d\n", cont);
	for (int i = 0; i < cont; i++) {
		printf("%d ", stair[i]);
	} printf("\n");

	return 0;
}