#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 10005;

struct trip {
	int t, c;
};

int n;
vector<trip> a;

double memo[10001][1121][7];

double getDesconto(int ori, int qtd) {
	if (qtd == 1) return ori;
	else if (qtd == 2) return 0.50 * ori;
	else if (qtd <= 6) return 0.25 * ori;
	return ori;
}

double solve(int i, int cur, int qtd) {
	if (i == n) return 0;
	if (memo[i][cur][qtd]) return memo[i][cur][qtd];

	double ret = DBL_MAX;

	if (cur < 120 && qtd <= 6 && qtd > 1)
		ret = min(ret, getDesconto(a[i].c, qtd) + solve(i+1, cur + a[i].t, qtd + 1));

	ret = min(ret, a[i].c + solve(i+1, a[i].t, 2));

	return memo[i][cur][qtd] = ret;
}

int main() {
	scanf("%d", &n);
	a.resize(n);

	for (int i = 0; i < n; i++) scanf("%d %d", &a[i].t, &a[i].c);

	printf("%.2lf\n", solve(0, 120, 1));

}