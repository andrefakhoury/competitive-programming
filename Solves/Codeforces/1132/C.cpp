#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 5005;

int sum[MAXN];
int stt[MAXN];

int n, q;

pii vec[MAXN];

void add(int l, int r) {
	for (int i = l; i <= r; i++) sum[i]++;
}

void sub(int l, int r) {
	for (int i = l; i <= r; i++) sum[i]--;
}

int count() {	
	int ans = 0;
	for (int i = 1; i <= n; i++) ans += sum[i] > 0;
	return ans;
}

int main() {
	scanf("%d%d", &n, &q);

	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		add(l, r);
		vec[i] = pii(l, r);
	}


	int ans = 0;
	for (int i = 1; i <= q; i++) {
		int l1 = vec[i].first;
		int r1 = vec[i].second;

		sub(l1, r1);

		int total = 0;
		for (int p = 1; p <= n; p++) {
			total += sum[p] > 0;
			stt[p] = stt[p-1] + (sum[p] == 1);
		}

		for (int j = i+1; j <= q; j++) {
			int l2 = vec[j].first;
			int r2 = vec[j].second;

			int cur = total - (stt[r2] - stt[l2-1]);
			ans = max(ans, cur);
		}

		add(l1, r1);
	}

	printf("%d\n", ans);
}