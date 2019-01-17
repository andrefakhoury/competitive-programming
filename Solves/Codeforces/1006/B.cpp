#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
//ios::sync_with_stdio(false);

#define inf 0x3f3f3f3f
#define MAXN 2005
#define MAXM 100000

typedef long long ll;
typedef pair<int, int> pii;

int a[MAXN];
int n, k;
priority_queue<pii> maximos;
int posi[MAXN];

int main () {
	scanf("%d%d", &n, &k);
	int ultimo = 0;

	for (int i = 1; i <= n; i++) {
		scanf("%d", a+i);
		maximos.push(mp(a[i], i));
	}

	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += maximos.top().first;
		posi[maximos.top().second] = 1;;
		ultimo = max(ultimo, maximos.top().second);
		maximos.pop();
	}

	printf("%d\n", ans);

	int somaAcum = 0, qtDias = 0;
	for (int i = 1; i <= n; i++) {
		somaAcum += a[i]; qtDias++;
		if (i != ultimo && posi[i]) {
			printf("%d ", qtDias);
			somaAcum = qtDias = 0;
		}
	}
	printf("%d\n", qtDias);

	return 0;
}