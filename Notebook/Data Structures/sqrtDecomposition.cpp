#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;

int a[MAXN];
long long block[MAXN];

class SqrtDec {
	private:
		int n, blockSize;

	public:
		SqrtDec() {}
		SqrtDec(int n) {
			this->n = n;
			this->blockSize = ceil(sqrt(n));
		}

		void build() {
			memset(block, 0, sizeof block);
			for (int i = 1; i <= n; i++)
				block[(i-1)/blockSize + 1] += a[i];
		}

		void update(int id, int val) {
			int old = a[id];
			a[id] = val;
			int curBlock = (id-1)/blockSize + 1;
			block[curBlock] += val - old;
		}

		long long query(int l, int r) {
			int lb = (l-1)/blockSize + 1;
			int rb = (r-1)/blockSize + 1;
			long long ret = 0;

			if (lb == rb) {
				for (int i = l; i <= r; i++) ret += a[i];
				return ret;
			}

			for (int i = l; i <= (lb)*blockSize; i++)
				ret += a[i];
			for (int i = (rb-1)*blockSize + 1; i <= r; i++)
				ret += a[i];
			for (int i = lb+1; i <= rb-1; i++)
				ret += block[i];

			return ret;
		}
};

int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int n; scanf("%d", &n);
		SqrtDec sq(n);

		for (int i = 1; i <= n; i++) scanf("%d", a+i);
		sq.build();

		int q; scanf("%d", &q);
		while (q--) {
			int l, r; scanf("%d%d", &l, &r);
			printf("%lld\n", sq.query(l, r));
		}
	}
}