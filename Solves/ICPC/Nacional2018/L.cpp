#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXX = 4 * MAXN;
const int inf = 0x3f3f3f3f;
#define LEFT(x) (x << 1)
#define RIGHT(x) ((x << 1) | 1)

bool isNotPrime[MAXN];
int maiorPrimo[MAXN];

struct query {
	int n, k, i, ans;
	query() {
		n = 2;
	}
	query(int a, int b, int c) {
		n = a;
		k = b;
		i = c;
	}
};

void crivo() {
	for (int i = 2; i < MAXN; i++) {
		if (isNotPrime[i]) continue;
		for (int j = 2*i; j < MAXN; j += i) {
			isNotPrime[j] = true;
		}
	}
}

int calcMaiorPrimo(int n) {
	int ret = -1;
	for (long long i = 2; i * i <= n; i++) {
		if (n%i == 0) {
			if (!isNotPrime[i]) ret = max(ret, int(i));
			if (!isNotPrime[n/int(i)]) ret = max(ret, n/int(i));
		}
	}
	if (!isNotPrime[n]) ret = max(ret, n);
	return ret;
}

void pre() {
	crivo();
	for (int i = 1; i < MAXN; i++)
		maiorPrimo[i] = calcMaiorPrimo(i);
}


bool cmp1(query& a, query& b) {
	return a.k < b.k;
}

bool cmp2(query& a, query& b) {
	return a.i < b.i;
}

//
int seg[4 * MAXN + 1];
int lazy[4 * MAXN + 1];

/* O(1) - Updates the current node with lazy and flusshes down the lazyness. */
void lazy_update(int cur, int l, int r){
	// Updating it.
	seg[cur] += lazy[cur];

	// If not a leaf node.
	if (l != r){
		// Marking children as lazy.
		lazy[LEFT(cur)] += lazy[cur];
		lazy[RIGHT(cur)] += lazy[cur];
	}

	// Marking current node as not lazy.
	lazy[cur] = 0;
}

/* O(1) - Merges the children's values. */
int merge(int nl, int nr){
	return nl + nr;
}

/* O(N) - Builds a Segment Tree "seg" out of the vector "v". */
void build(int cur, int l, int r){
	int m = (l + r) / 2;

	// Leaf node.
	if (l == r){
		seg[cur] = 0;
		return;
	}

	// Going down both ways.
	build(LEFT(cur), l, m);
	build(RIGHT(cur), m + 1, r);

	// Merging children's results.
	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

/* O(Log(N)) - Updates the range [i..j]. */
void update(int cur, int l, int r, int i, int j, int x){
	int m = (l + r) / 2;

	// Updates current node with lazy if it needs an update.
	if (lazy[cur] != 0){
		lazy_update(cur, l, r);
	}

	// [l..r] is outside update range [i..j].
	if (l > j or r < i){
		return;
	}

	// [l..r] is fully inside the update range [i..j].
	if (l >= i and r <= j){
		// Updating with x.
		lazy[cur] = x;
		lazy_update(cur, l, r);
		return;
	}

	// Going down both ways.
	update(LEFT(cur), l, m, i, j, x);
	update(RIGHT(cur), m + 1, r, i, j, x);

	// Merging children's results.
	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);
}

/* O(Log(N)) - Returns the content of the range [i, j] of the Segment Tree. */
int getQuery(int cur, int l, int r, int i, int j){
	int nl, nr, m = (l + r) / 2;

	// Updates current node with lazy if it needs an update.
	if (lazy[cur] != 0){
		lazy_update(cur, l, r);
	}

	// [l..r] is outside getQuery range [i..j].
	if (l > j or r < i){
		// Returning a value that will not affect the result.
		return 0;
	}

	// [l..r] is fully inside the getQuery range [i..j].
	if (l >= i and r <= j){
		return seg[cur];
	}

	// Going down both ways.
	nl = getQuery(LEFT(cur), l, m, i, j);
	nr = getQuery(RIGHT(cur), m + 1, r, i, j);

	// Merging children's results.
	seg[cur] = merge(seg[LEFT(cur)], seg[RIGHT(cur)]);

	// Merging the getQuery results.
	return merge(nl, nr);
}


////



int getVal(int i, int j, int k) {
	int ret = 0;
	for (; i <= j; i++) {
		if (maiorPrimo[i] <= k) ret++;
	}
	return ret;
}



int main() {
	pre();
	build(1, 1, MAXX);

	int q; scanf("%d", &q);
	vector<query> queries(q);

	for (int i = 1; i <= q; i++) {
		int n, k; scanf("%d%d", &n, &k);
		queries.push_back(query(n, k, i));

		// printf("%d\n", solve(n, k));
	}

	sort(queries.begin(), queries.end(), cmp1);
	map<int, int> last;
	for (int i = 0; i < (int)queries.size(); i++) {
		int n = queries[i].n;
		int k = queries[i].k;

		if (last[k] < n) {
			last[k] = max(last[k], 2);
			int val = getVal(last[k], n, k);
			// update_tree(1, 0, MAXX, last[k], n, val);
			update(1, 1, MAXX, last[k], n, val);
			last[k] = n;
		}

		int ans = 0;//query_tree(1, 0, MAXX, 2, n);
		queries[i].ans = ans;
	}


	sort(queries.begin(), queries.end(), cmp2);
	for (int i = 0; i < (int)queries.size(); i++) {
		printf("%d\n", queries[i].ans);
	}


}