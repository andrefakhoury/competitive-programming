#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 200010;

int prox[MAXN];
bool vis[MAXN];
pair<int, int> vet[MAXN];
unordered_set<int> roda[MAXN];

int main() {
	int n; scanf("%d", &n);
	if (n == 3) return !printf("1 2 3\n");

	for (int i = 1; i <= n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		roda[i].insert(x);
		roda[i].insert(y);
		vet[i] = mp(x, y);
	}

	for (int i = 1; i <= n; i++) {
		int op1 = vet[i].first;
		int op2 = vet[i].second;

		if (roda[op1].find(op2) != roda[op1].end()) {
			prox[i] = op1;
			prox[op1] = op2;
		} else {
			prox[i] = op2;
			prox[op2] = op1;
		}
	}

	for (int i = 1; !vis[i]; i = prox[i]) {
		vis[i] = true;
		printf("%d ", i);
	}

	return !printf("\n");
}