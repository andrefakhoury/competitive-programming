#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int main() {
	int n, m; scanf("%d%d", &n, &m);
	vector<int> a(n), b(m);

	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) scanf("%d", &b[i]);

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	ll ans = 0;
	for (int i = 0; i < min(n, m); i++)
		ans += max(b[i] - a[i], 0);

	printf("%lld\n", ans);
}