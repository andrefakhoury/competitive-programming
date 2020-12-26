#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 1e5 + 5;

bool isComp[MAXN];

void sieve() {
	for (int i = 2; i < MAXN; i++) {
		if (isComp[i]) continue;
		for (int j = 2 * i; j < MAXN; j += i) {
			isComp[j] = true;
		}
	}
}

struct Number {
	int n, mp;

	Number() {}
	Number(int i) {
		n = i;
		mp = -1;

		for (i = 1; i * i <= n; i++) {
			if (n%i) continue;
			if (!isComp[i]) mp = max(mp, i);
			if (!isComp[n/i]) mp = max(mp, n/i);
		}

		if (!isComp[n]) mp = max(mp, n);
	}

	bool operator<(Number& p) const {
		return mp < p.mp;
	}
};

struct Query {
	int N, K, id;

	Query() {}

	void read(int i) {
		scanf("%d%d", &N, &K);
		id = i;
	}

	bool operator<(Query& q) const {
		return K < q.K;
	}
};

struct ST {
	vector<ll> seg, lazy;
 
	ST() {
		seg = vector<ll>(4 * MAXN);
		lazy = vector<ll>(4 * MAXN);
 
		fill(seg.begin(), seg.end(), 0ll);
		fill(lazy.begin(), lazy.end(), 0ll);
	}
 
	ll merge(ll i, ll j) {
		return i + j;
	}
 
	void prop(int p, int i, int j) {
		if (!lazy[p]) return;
 
		seg[p] += lazy[p] * (j - i + 1);
 
		if (i != j) {
			lazy[2 * p] += lazy[p];
			lazy[2 * p + 1] += lazy[p];
		}
 
		lazy[p] = 0;
	}
 
	ll query(int p, int i, int j, int l, int r) {
		if (i > j || j < l || i > r) return 0;
		prop(p, i, j);
 
 
		if (i >= l && j <= r) {
			return seg[p];
		}
 
		int m = (i + j) / 2;
 
		ll L = query(2 * p, i, m, l, r);
		ll R = query(2 * p + 1, m+1, j, l, r);
 
		return merge(L, R);
	}
 
	ll query(int l, int r) {
		return query(1, 1, MAXN - 1, l, r);
	}
 
	void update(int p, int i, int j, int l, int r, ll x) {
 
		prop(p, i, j);
 
		if (i > j || j < l || i > r) return;
 
		if (i >= l && j <= r) {
			lazy[p] += x;
			prop(p, i, j);
			return;
		}
 
		int m = (i + j) / 2;
 
		update(2 * p, i, m, l, r, x);
		update(2 * p + 1, m+1, j, l, r, x);
 
		seg[p] = merge(seg[2 * p], seg[2 * p + 1]);
	}
 
	void update(int l, int r, ll x) {
		update(1, 1, MAXN-1, l, r, x);
	}

	void update(int x) {
		update(x, x, 1);
	}
};

int main() {
	sieve();
	vector<Number> numbers;
	for (int i = 2; i < MAXN; i++) numbers.emplace_back(i);

	int q; scanf("%d", &q);
	vector<Query> queries(q);
	for (int i = 0; i < q; i++) queries[i].read(i);

	sort(numbers.begin(), numbers.end());
	sort(queries.begin(), queries.end());

	ST seg;
	int last = -1, id = 0;
	vector<int> ans(q);

	for (Query& que : queries) {
		while (last <= que.K) {
			while(id < MAXN && numbers[id].mp <= last) {
				seg.update(numbers[id].n);
				id++;
			}

			last++;
		}

		ans[que.id] = seg.query(1, que.N);
	}

	for (int x : ans) printf("%d\n", x);

	return 0;
}	