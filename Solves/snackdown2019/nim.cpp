#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

const int MAXN = 105;
typedef long long ll;

int A[MAXN], B[MAXN];
int n, m;

int predict() {
	int num = 0;
	for (int i = 0; i < n; i++) num ^= A[i];
	for (int i = 0; i < m; i++) num ^= B[i];

	if (num != 0) return 1;
	return 0;
}

int main() {
	int t; scanf("%d", &t);
	ll sumA, sumB;

	while(t--) {
		scanf("%d%d", &n, &m);
		sumA = sumB = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", A+i);
			sumA += A[i];
		}

		for (int i = 0; i < m; i++) {
			scanf("%d", B+i);
			sumB += B[i];
		}

		if (sumA != sumB || n != m) printf("Alice\n");
		else printf("Bob\n");

	}

	return 0;
}