// number of different numbers on [l..r]

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 30000;
const int BKSZ = 333;

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
	//everything is 0-based
	int n, q, curAns;
	vector<int> vec;
	vector<Query> qry;

	public:
	Mo() {}
	Mo(vector<int>& vec) {
		this->vec = vec;
		this->q = 0;
		this->curAns = 0;
	}

	void addQuery(int l, int r) {
		qry.push_back(Query(q++, l, r));
	}

	void add(int id) { }

	void remove(int id) { }

	int getAnswer() {
		return curAns;
	}

	vector<int> MoAlgorithm() { //O( (n+q) * sqrt(n) * f)
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