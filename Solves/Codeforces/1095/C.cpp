#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 200010;
const int MAXP = 1000000000;

ll p2[MAXN];

void initi() {
	p2[0] = 1;
	for (int i = 1; p2[i-1] < MAXP; i++) {
		p2[i] = 2 * p2[i-1];
	}
}

bool dapracontinuar(int n, int k) {
	if (k < 0 || k < __builtin_popcount(n) || k > n) return false;
	return true;
}


int main() {
	int n, k; scanf("%d%d", &n, &k);
	initi();



	if (k < __builtin_popcount(n) || k > n) return !printf("NO\n");
	printf("YES\n");

	for (int i = 30; i >= 0; i--) {
		int nex = n - p2[i];
		while(dapracontinuar(n-p2[i], k-1)) {
			n -= p2[i];
			k--;
			printf("%lld ", p2[i]);
		}
	}

	return !printf("\n");

	// if (k == __builtin_popcount(n)) {
	// 	for (int i = 0; i < 31; i++) {
	// 		if ((n>>i)&1 == 1) printf("%lld ", p2[i]);
	// 	} printf("\n");
	// }

	// return 0;
	// for (int i = 0; i < 31; i++) {
	// 	printf("%d", (n>>i)&1);
	// } printf("\n");


}