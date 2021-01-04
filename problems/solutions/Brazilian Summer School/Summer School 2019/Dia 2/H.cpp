#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	while (~scanf("%d%d", &n, &k)) {
		priority_queue<int> pq;
		long long sum = 0;

		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			sum += x;

			if (i%(k+1) == 0) {
				pq.push(-x);
			} else if (i > k) {
				int topo = -pq.top();
				if (x > topo) {
					pq.pop();
					pq.push(-x);
				}
			}
		}

		while(pq.size()) {
			sum += pq.top();
			pq.pop();
		}

		printf("%lld\n", sum);
	}

	return 0;
}