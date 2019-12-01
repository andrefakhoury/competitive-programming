#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int main() {
	int n, m; scanf("%d%d", &n, &m);

	set<int> row, col;
	while(m--) {
		int x, y; scanf("%d%d", &x, &y);
		row.emplace(x);
		col.emplace(y);

		ll i = n - row.size();
		ll j = n - col.size();
		printf("%lld ", i * j);
	}
	return 0;	
}
