#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e6;
const int MAXN = 2e5 + 5;
const int MAXD = 200;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int n, a[MAXN];
int dist[MAXN][2];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a+i);
	memset(dist, INF, sizeof dist);

	for (int i = 1; i <= n; i++)
		dist[i][a[i]%2] = 0;

	for (int i = 1; i <= n; i++)
		if (i + a[i] <= n) dist[i][a[i+a[i]]%2] = min(dist[i][a[i+a[i]]%2], 1 + dist[i+a[i]][a[i+a[i]]%2]);
	for (int i = n; i >= 1; i--)
		if (i - a[i] >= 1) dist[i][a[i-a[i]]%2] = min(dist[i][a[i-a[i]]%2], 1 + dist[i-a[i]][a[i-a[i]]%2]);

	bool flag = true;
	while(flag) {
		flag = false;
		for (int i = 1; i <= n; i++) {
			if (i + a[i] <= n) {
				int old = dist[i][a[i+a[i]]%2];
				dist[i][a[i+a[i]]%2] = min(dist[i][a[i+a[i]]%2], 1 + dist[i+a[i]][a[i+a[i]]%2]);
				if (old != dist[i][a[i+a[i]]%2]) flag = true;
			}
			if (i - a[i] >= 1) {
				int old = dist[i][a[i-a[i]]%2];
				dist[i][a[i-a[i]]%2] = min(dist[i][a[i-a[i]]%2], 1 + dist[i-a[i]][a[i-a[i]]%2]);
				if (old != dist[i][a[i-a[i]]%2]) flag = true;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d ", dist[i][1-a[i]%2]);
	}
	printf("\n");

	return 0;
}