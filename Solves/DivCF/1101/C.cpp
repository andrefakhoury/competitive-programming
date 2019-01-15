#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct node {
	int c, d;
	struct node *next, *prev;

	node();
	node(int color, int delicious, struct node* n, struct node* p) {
		c = color;
		d = delicious;
		next = n;
		prev = p;
	}
};

struct deq {
	node *begin, *end;
	deq() {
		begin = NULL;
		end = NULL;
	}

	void insert_front(int c, int d) {
		node* a = this->begin;
		node* n = (node*) malloc(sizeof(node));
		*n = node(c, d, a, NULL);
		
		if (a) a->prev = n;
		this->begin = n;

		if (this->end == NULL) this->end = n;
	}

	void insert_back(int c, int d) {
		node* a = this->end;
		node* n = (node*) malloc(sizeof(node));
		*n = node(c, d, NULL, a);

		if (a) a->next = n;
		this->end = n;

		if (this->begin == NULL) this->begin = n;
	}

	void print() {
		node* aux = this->begin;

		while(aux) {
			printf("[%d %d] ", aux->c, aux->d);
			aux = aux->next;
		} cout << "\n";
	}

	void clear() {
		node* aux = this->begin;
		while(aux != NULL) {
			aux = aux->next;
			free(this->begin);
			this->begin = aux;
		}
	}

	long long getAnswer(int color, int k) {

		long long ans = 0;
		vector<long long> memo;
		
		for (node* i = this->begin; i != NULL; i = i->next) {
			if (abs(i->c - color) > k) continue;

			long long cur = i->d;
			memo.push_back(cur);

			for (node* j = i->next; j != NULL; j = j->next) {
				if (abs(j->c - color) > k) continue;
				cur += j->d;
				memo.push_back(cur);
			}

			for (int j = 0; j < memo.size(); j++)
				ans = max(ans, memo[j]);
			
			memo.clear();
		}

		return ans;
	}
	
};


int main() {
	int q, k; scanf("%d%d", &q, &k);

	deq dq = deq();
	long long prev = 0;

	while(q--) {
		int kind, C; scanf("%d %d", &kind, &C);
		int c = C^prev, d;


		if (kind == 1) {
			scanf("%d", &d);
			dq.insert_front(c, d);
		} else if (kind == 2) {
			scanf("%d", &d);
			dq.insert_back(c, d);
		} else if (kind == 3) {
			long long ans = dq.getAnswer(c, k);
			printf("%lld\n", ans);
			prev = ans;
		}

		// dq.print();
		// printf("%d %d %d\n", kind, c, d);
	}

	dq.clear();
}