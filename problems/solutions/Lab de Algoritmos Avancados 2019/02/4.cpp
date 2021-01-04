#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 100005;

int s[MAXN];

vector<int> dep[MAXN];
vector<int> ins[MAXN];
bool hasGift[MAXN];
bool alOpen[MAXN];

int main() {
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", s+i);

	for (int i = 1; i <= n; i++) {
		int q; scanf("%d", &q);
		hasGift[i] = q == 0;

		while(q--) {
			int x; scanf("%d", &x);
			dep[x].push_back(i);
			ins[i].push_back(x);
		}
	}

	int ans = 0, used = 0;

	priority_queue<pair<int, int> > pq;

	for (int i = 1; i <= n; i++) {
		if (dep[i].size() == 0) 
			pq.push(make_pair(s[i], i));
	}

	while (used < k and pq.size()) {

		int u = pq.top().second;
		alOpen[u] = true;

		pq.pop();

		ans += hasGift[u] == true;

		for (int v : ins[u])
			if (!alOpen[v]) pq.push(make_pair(s[v], v));

		used++;
	}

	printf("%d\n", ans);
}

