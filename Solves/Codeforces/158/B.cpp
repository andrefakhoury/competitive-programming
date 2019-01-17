#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f3f

#define MAXN 100005
#define MAXM 100000

typedef long long ll;
typedef pair<int, int> pii;

int qtd[10];

int main() {
	int x, n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x); qtd[x]++;
	}

	int ans = qtd[4];

	while(qtd[3]) {
		if (qtd[1]) qtd[1]--;
		qtd[3]--;
		ans++;
	}

	while(qtd[2] > 1) {
		qtd[2] -= 2;
		ans++;
	}

	if (qtd[2] == 1) {
		qtd[2]--;
		qtd[1] -= 2;
		ans++;
	}

	while(qtd[1] > 0) {
		qtd[1] -= 4;
		ans++;
	}

	printf("%d\n", ans);
	return 0;



}