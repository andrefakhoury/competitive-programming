#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100010;
typedef long long ll;
ll a[MAXN], b[MAXN];

int main() {
	int t; scanf("%d", &t);

	while (t--) {
		int n, k; scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%lld", a+i);
		for (int i = 1; i <= n; i++) scanf("%lld", b+i);

		bool nie = false;

		for (int i = 1; (!nie) && i <= n-2; i++) {
			if (a[i] > b[i]) nie = true;

			if (a[i] < b[i]) {
				k = b[i]-a[i];
				a[i] += k;
				a[i+1] += 2*k;
				a[i+2] += 3*k;
			}
		}
        
		for (int i = 1; (!nie) && i <= n; i++) nie = a[i] != b[i];

		printf("%s\n", nie ? "NIE" : "TAK");
	}
	
	return 0;
}