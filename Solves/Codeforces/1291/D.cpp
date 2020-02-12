#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;
const int BKSZ = 444;

const int MOD[2] = {1000000009, 1000000007};
const int P[2] = {31, 37};
int curPow[2][MAXN];
int invPow1;
int invPow2;
int v[MAXN];

inline ll invv(ll a, ll m) {
	ll b = m-2;
	a %= m;
	ll res = 1;
	while (b > 0) {
		if (b & 1) res = (res * a) % m;
		a = (a * a) % m;
		b >>= 1;
	}
	return res;
}

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

inline int add(int a, int b, int k) {
	a += b;
	if (a >= MOD[k]) a -= MOD[k];
	return a;
}

inline int sub(int a, int b, int k) {
	a -= b;
	if (a < 0) a += MOD[k];
	return a;
}

inline int mul(int a, int b, int k) {
	return ll(a) * b % MOD[k];
}

class Mo {
	int n, q, curAns;
	vector<Query> qry;

	pii hashA, hashB;
	int sz;

	public:
	Mo() {
		this->q = 0;
		this->curAns = 0;
		hashA = {0, 0};
		hashB = {0, 0};
		sz = 0;
	}

	inline void addQuery(int l, int r) {
		qry.push_back(Query(q++, l, r));
	}

	inline pii pushback(pii cur, int x) {
		cur.fi = add(cur.fi, mul(x, curPow[0][sz], 0), 0);
		cur.se = add(cur.se, mul(x, curPow[1][sz], 1), 1);
		return cur;
	}

	inline pii popback(pii cur, int x) {
		cur.fi = sub(cur.fi, mul(x, curPow[0][sz-1], 0), 0);
		cur.se = sub(cur.se, mul(x, curPow[1][sz-1], 1), 1);
		return cur;
	}

	inline pii pushfront(pii cur, int x) {
		cur.fi = mul(cur.fi, P[0], 0);
		cur.se = mul(cur.se, P[1], 1);
		cur.fi = add(cur.fi, x, 0);
		cur.se = add(cur.se, x, 1);
		return cur;
	}

	inline pii popfront(pii cur, int x) {
		cur.fi = sub(cur.fi, x, 0);
		cur.se = sub(cur.se, x, 1);
		cur.fi = mul(cur.fi, invPow1, 0);
		cur.se = mul(cur.se, invPow2, 1);
		return cur;
	}

	inline void addLeft(int i) {
		hashA = pushfront(hashA, v[i]);
		hashB = pushback(hashB, v[i]);
		sz++;
	}

	inline void addRight(int i) {
		hashA = pushback(hashA, v[i]);
		hashB = pushfront(hashB, v[i]);
		sz++;
	}

	inline void removeLeft(int i) {
		hashA = popfront(hashA, v[i]);
		hashB = popback(hashB, v[i]);
		sz--;
	}

	inline void removeRight(int i) {
		hashA = popback(hashA, v[i]);
		hashB = popfront(hashB, v[i]);
		sz--;
	}

	inline int getAnswer(int l, int r) {
		return (r - l + 1) < 2 || hashB != hashA;
	}

	vector<int> MoAlgorithm() {
		sort(qry.begin(), qry.end());
		vector<int> ans(q, 0);

		int l = 0, r = 0;
		for (int i = 0; i < (int)qry.size(); i++) {
			while (l < qry[i].l) removeLeft(l++);
			while (l > qry[i].l) addLeft(l--);
			while (r <= qry[i].r) addRight(r++);
			while (r > qry[i].r+1) removeRight(r--);
			ans[qry[i].id] = getAnswer(qry[i].l, qry[i].r);
		}

		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	invPow1 = invv(P[0], MOD[0]);
	invPow2 = invv(P[1], MOD[1]);

	for (int k = 0; k < 2; k++) {
		curPow[k][0] = 1;
		for (int i = 1; i < MAXN; i++) {
			curPow[k][i] = mul(curPow[k][i-1], P[k], k);
		}
	}

	string s; cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		v[i] = s[i] - 'a' + 1;
	}

	Mo mo;
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r;
		mo.addQuery(l-1, r-1);
	}

	vector<int> ans = mo.MoAlgorithm();
	for (int x : ans)
		cout << (x ? "Yes" : "No") << '\n';

	return 0;
}