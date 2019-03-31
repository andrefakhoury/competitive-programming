// https://open.kattis.com/problems/thief

#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e6 + 5;
const int MAXK = 1e5 + 5;

vector<pii> a;
ll ans[MAXK];

int main() {
	int n, k; scanf("%d%d", &n, &k);

	for (int i = 0; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a.emplace_back(x, y);
	}

	sort(a.begin(), a.end());

	

	for (int i = 1; i <= k; i++) printf("%lld ", ans[i]);
	return !printf("\n");
}