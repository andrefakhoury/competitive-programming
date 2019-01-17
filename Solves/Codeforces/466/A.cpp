#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, a, b; cin >> n >> m >> a >> b;

	int ans = n * a;

	int op1 = 0;
	int need = n;
	while(need > 0) {
		need -= m;
		op1 += b;
	}
	ans = min(ans, op1);

	op1 = 0;
	need = n;
	while(need-m >= 0) {
		need -= m;
		op1 += b;
	}
	op1 += need * a;
	ans = min(ans, op1);

	printf("%d\n", ans);
	return 0;
}
