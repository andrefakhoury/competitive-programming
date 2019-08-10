#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int a[MAXN];

class waveletTree {
public:

	int lo, hi;
	waveletTree *l, *r;

	vector<int> f;

	// interval [i, j]; minimum element is x, maximum is y
	waveletTree(int i, int j, int x, int y) {
		lo = x, hi = y;

		if (i > j) return; // out of bounds
		f.reserve(j - i + 1);

		if (x == y) { // array is homogenous (e.g. 2 2 2)
			f.push_back(0);

			while (i <= j) {
				f.push_back(f.back() + 1);
				i++;
			}

			l = r = NULL;
			return;
		}

		int mi = (lo + hi) / 2;

		auto lessThanMid = [mi](int x) {
			return x <= mi;
		};


		f.push_back(0);

		for (int k = i; k <= j; k++) f.push_back(f.back() + lessThanMid(a[k]));

		int p = stable_partition(a+i, a+j, lessThanMid) - a - 1;

		this->l = new waveletTree(i, p, lo, mi);
		this->r = new waveletTree(p+1, j, mi+1, hi);
	}

	void print() {
		printf(">> %d %d\n", lo, hi);
		for (int i : f) printf("%d ", i);
		printf("\n");

		if (l) l->print();
		if (r) r->print();
	}

	// qtt of elements in range [l..r] <= k
	int kOrLess(int l, int r, int k) {

		if (l > r || k < lo) return 0; // out of bounds

		if (hi <= k) return r - l + 1; // every element

		int L = f[l-1];
		int R = f[r];

		return this->l->kOrLess(L+1, R, k) + this->r->kOrLess(l - R, r - R, k);
	}

};


int main() {

	int n = 5;
	for (int i = 1; i <= n; i++) a[i] = i;

	waveletTree root(1, n, 1, n);

	printf("%d\n", root.kOrLess(2, 5, 3));
}