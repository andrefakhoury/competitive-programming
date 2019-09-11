// number of different numbers on [l..r]

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000;
const int BKSZ = (int)sqrt(MAXN);

class Query {

public:
	int id, l, r;
	Query() {}
	Query(int id, int l, int r) {
		this->id = id;
		this->l = l;
		this->r = r;
	}

	bool operator< (const Query& b) const {
		if (l/BKSZ == b.l/BKSZ) return r < b.r;
		return l/BKSZ < b.l/BKSZ;
	}
};

class Mo {
	int n, q, curAns;
	vector<int> vec;
	vector<Query> qry;
	vector<int> freq;

public:
	Mo() {}
	Mo(vector<int>& vec) {
		this->vec = vec;
		this->q = 0;
		this->curAns = 0;
		freq.resize(1000001);
	}

	void addQuery(int l, int r) {
		qry.push_back(Query(q++, l, r));
	}

	void add(int id) {
		freq[vec[id]]++;
		curAns += freq[vec[id]] == 1;
	}

	void remove(int id) {
		freq[vec[id]]--;
		curAns -= freq[vec[id]] == 0;
	}

	int getAnswer() {
		return curAns;
	}

	vector<int> MoAlgorithm() {
		vector<int> ans(q);
		sort(qry.begin(), qry.end());

		int l = 1, r = 0;
		for (int i = 0; i < (int)qry.size(); i++) {
			while (r < qry[i].r) add(++r);
			while (r > qry[i].r) remove(r--);
			while (l < qry[i].l) remove(l++);
			while (l > qry[i].l) add(--l);
			ans[qry[i].id] = getAnswer();
		}

		return ans;
	}
};

int main() {
	int n; scanf("%d", &n);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	Mo mo(a);
	int q; scanf("%d", &q);

	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		mo.addQuery(l-1, r-1);
	}
	
	vector<int> ans = mo.MoAlgorithm();
	for (int i : ans) printf("%d\n", i);

	return 0;
}