#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair

#define MAXN 105
#define MAXM 1000000005

typedef pair<int, int> pii;

int qt[MAXN];

int main() {
	int n, k, x;
	scanf("%d%d", &n, &k);
	vector<int> vec;
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		vec.pb(x);
		qt[x]++;
	}

	int soma = 0;
	for (int i = 0; i < MAXN; i++) {
		if (qt[i] >= 1) soma++;
	}

	if (soma < k) {
		printf("NO\n"); return 0;
	} else {
		printf("YES\n");
		int j = 0;
		for (int i = 0; i < n; i++) {
			if (qt[vec[i]] == 1) {
				printf("%d ", i+1);
				j++;
			}
			qt[vec[i]]--;
			if (j == k) break;
		}
	}
	printf("\n");

	
	return 0;
}