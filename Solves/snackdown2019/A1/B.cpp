#include <bits/stdc++.h>
using namespace std;
#define MAXN 205

bool isPrime[MAXN];
vector<int> divs[MAXN];

bool isSemiPrime[MAXN];
map<int, bool> sum;

int main() {
	int t, n = 200; scanf("%d", &t);

	for (int i = 0; i <= n; i++) isPrime[i] = true;
	for (int i = 0; i <= n; i++) isSemiPrime[i] = false;

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2*i; j <= n; j += i) {
				isPrime[j] = false;

				divs[j].push_back(i);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (!isPrime[i] && (int)divs[i].size() == 2 && divs[i][0] * divs[i][1] == i)
			isSemiPrime[i] = true;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (isSemiPrime[i] && isSemiPrime[j]) sum[i+j] = true;
		}
	}


	while(t--) {
		scanf("%d", &n);
		
		if (sum[n]) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}