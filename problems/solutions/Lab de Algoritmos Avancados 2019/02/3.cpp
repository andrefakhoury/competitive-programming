#include <queue>
#include <stdio.h>
using namespace std;

int main() {
	char inp[50];
	int q, p;

	priority_queue<pair<int, int> > pq;
	while (scanf("%s ", inp), inp[0] != '#') {
		scanf("%d %d ", &q, &p);

		for (int i = 1; i <= 10000; i++) {
			pq.push(make_pair(-i*p, -q));
		}
	}

	int k; scanf("%d", &k);

	while(k--) {
		printf("%d\n", -pq.top().second);
		pq.pop();
	}
}