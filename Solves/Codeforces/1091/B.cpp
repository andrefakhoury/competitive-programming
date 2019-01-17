#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

int main() {
	//ios::sync_with_stdio(false);
	int n; scanf("%d", &n);
	vector<pii> ob(n);
	vector<pii> cl(n);

	for (int i = 0; i < n; i++) scanf("%d%d", &ob[i].first, &ob[i].second);
	for (int i = 0; i < n; i++) scanf("%d%d", &cl[i].first, &cl[i].second);

	sort(ob.begin(), ob.end());
	sort(cl.begin(), cl.end());

	printf("%d %d\n", ob[0].first + cl[n-1].first, ob[0].second + cl[n-1].second);

	return 0;
}