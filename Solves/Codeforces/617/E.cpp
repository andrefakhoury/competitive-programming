#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5+5, MAXK = 1e6+5;
const int BKSZ = (int)sqrt(MAXN);

inline int64_t gilbertOrder(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t subSquareSize = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * subSquareSize;
	int64_t add = gilbertOrder(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
	return ans;
}

class Query {

public:
	int id, l, r;
	int64_t ord;

	Query() {}
	Query(int id, int l, int r) {
		this->id = id;
		this->l = l;
		this->r = r;
		this->ord = gilbertOrder(l, r, 21, 0);
	}

	bool operator< (const Query& b) const {
		return ord < b.ord;
	}
};

int cnt[1 << 20];
int pref[MAXN];

class Mo {
	int n, q, k;
	ll curAns;
	vector<int> vec;
	vector<Query> qry;

public:
	Mo() {}
	Mo(vector<int>& vec, int k) {
		this->vec = vec;
		this->q = 0;
		this->curAns = 0;
		this->k = k;

		for (int i = 1; i <= vec.size(); i++)
			pref[i] = pref[i-1] ^ vec[i-1];

	}

	void addQuery(int l, int r) {
		qry.push_back(Query(q++, l, r));
	}

	void add(int id) {
		int p = pref[id];
		curAns += cnt[p^k];
		cnt[p]++;
	}

	void remove(int id) {
		int p = pref[id];
		cnt[p]--;
		curAns -= cnt[p^k];
	}

	vector<ll> MoAlgorithm() {
		vector<ll> ans(q);
		sort(qry.begin(), qry.end());

		int l = 1, r = 0;
		for (int i = 0; i < (int)qry.size(); i++) {
			while (r < qry[i].r) add(++r);
			while (r > qry[i].r) remove(r--);
			while (l < qry[i].l) remove(l++);
			while (l > qry[i].l) add(--l);
			ans[qry[i].id] = curAns;
		}

		return ans;
	}
};

int main() {
	int n, q, k; scanf("%d%d%d", &n, &q, &k);
	vector<int> a(n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	Mo mo(a, k);

	while(q--) {
		int l, r; scanf("%d%d", &l, &r);
		mo.addQuery(l-1, r);
	}
	
	vector<ll> ans = mo.MoAlgorithm();
	for (ll i : ans) printf("%lld\n", i);

	return 0;
}