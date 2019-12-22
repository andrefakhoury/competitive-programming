#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;

int main() {
	int n;
	while(~scanf("%d", &n)) {
		stack<int> s;
		queue<int> q;
		priority_queue<int> pq;
		bool cS, cQ, cPQ;
		cS = cQ = cPQ = true;

		while(n--) {
			int op, x; scanf("%d%d", &op, &x);

			if (op == 1) {
				s.push(x);
				q.push(x);
				pq.push(x);
			} else {
				if (s.size() == 0) cS = false;
				if (q.size() == 0) cQ = false;
				if (pq.size() == 0) cPQ = false;

				if (cS and s.top() != x) cS = false;
				if (cQ and q.front() != x) cQ = false;
				if (cPQ and pq.top() != x) cPQ = false;

				if (cS) s.pop();
				if (cQ) q.pop();
				if (cPQ) pq.pop();
			}
		}

		if (cS and !cQ and !cPQ) printf("stack\n");
		else if (!cS and cQ and !cPQ) printf("queue\n");
		else if (!cS and !cQ and cPQ) printf("priority queue\n");
		else if (!cS and !cQ and !cPQ) printf("impossible\n");
		else printf("not sure\n");
	}
}