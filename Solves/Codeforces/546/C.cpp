#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 120005;

void print(int g, int w = -1, int debug = -1) {
	printf("%d", g);
	if (w != -1) printf(" %d", w);
	if (debug != -1) printf(" %d", debug);
	printf("\n");

	exit(0);
}

int main() {
	int n; scanf("%d", &n);
	int k1, k2;
	deque<int> d1, d2;

	scanf("%d", &k1);
	for (int i = 1; i <= k1; i++) {
		int x; scanf("%d", &x);
		d1.push_front(x);
	}
	
	scanf("%d", &k2);
	for (int i = 1; i <= k2; i++) {
		int x; scanf("%d", &x);
		d2.push_front(x);
	}

	int m = 0;
	while(1) {
		if (m > 2384) print(-1);

		if (d1.size() == 0) print(m, 2);
		if (d2.size() == 0) print(m, 1);

		int t1 = d1.back();
		int t2 = d2.back();

		d1.pop_back(); d2.pop_back();
		
		// printf("%d: %d[%d] vs %d[%d]\n", m, t1, d1.size(), t2, d2.size());

		if (t1 > t2) {
			d1.push_front(t2);
			d1.push_front(t1);
		} else {
			d2.push_front(t1);
			d2.push_front(t2);
		}

		m++;
	}
}