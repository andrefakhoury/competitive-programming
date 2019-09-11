// https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/sherlock-and-inversions/
// number of inversions on [l..r]

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5;
const int BKSZ = (int)sqrt(MAXN);

class BIT {
	ll bt[MAXN+10];

	public:
	BIT() {
		memset(bt, 0, sizeof bt);
	}

	void update(int i, int val) {
		while (i <= MAXN) {
			bt[i] += val;
			i += i&-i;
		}
	}

	ll query(int i) {
		ll ret = 0;
		while (i > 0) {
			ret += bt[i];
			i -= i&-i;
		}
		return ret;
	}

	ll query(int i, int j) {
		if (i > j) return 0;
		if (i == j) return query(i);
		
		return query(j) - query(i-1);
	}
};

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
	int n, q;
	ll curAns;
	vector<int> vec;
	vector<Query> qry;
	BIT st;

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

	void add(int id, bool LEFT) {
		st.update(vec[id], 1);
		if (LEFT) curAns += st.query(1, vec[id]-1);
		else curAns += st.query(vec[id]+1, MAXN);
	}

	void remove(int id, bool LEFT) {
		st.update(vec[id], -1);
		if (LEFT) curAns -= st.query(1, vec[id]-1);
		else curAns -= st.query(vec[id]+1, MAXN);
	}

	ll getAnswer() {
		return curAns;
	}

	vector<ll> MoAlgorithm() {
		vector<ll> ans(q);
		sort(qry.begin(), qry.end());

		int l = 1, r = 0;
		for (int i = 0; i < (int)qry.size(); i++) {
			while (r < qry[i].r) add(++r, false);
			while (r > qry[i].r) remove(r--, false);
			while (l < qry[i].l) remove(l++, true);
			while (l > qry[i].l) add(--l, true);
			ans[qry[i].id] = getAnswer();
		}

		return ans;
	}
};

void comprime(vector<int>& v) {
	vector<int> a = v;

	sort(a.begin(), a.end());

	map<int, int> h;
	int cur = 3;

	h[a[0]] = cur;
	for (int i = 1; i < (int)a.size(); i++) {
		if (a[i] != a[i-1]) cur++;
		h[a[i]] = cur;
	}

	for (int i = 0; i < (int)v.size(); i++) {
		v[i] = h[v[i]];
	}
}

int main() {
	int n, q; scanf("%d%d", &n, &q);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	comprime(a);
	Mo mo(a);

	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		mo.addQuery(l-1, r-1);
	}
	
	vector<ll> ans = mo.MoAlgorithm();
	for (ll i : ans) printf("%lld\n", i);

	return 0;
}