#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Wavelet Tree - 0-based pls
struct Wavelet {
	vector<int> mapLeft, mapRight;
	ll lo, hi, mi;
	int sz;
	Wavelet *L, *R;

	Wavelet(vector<ll>& v) {
		lo = *min_element(v.begin(), v.end());
		hi = *max_element(v.begin(), v.end());
		mi = (lo + hi) / 2;

		L = R = NULL;

		if (lo == hi) { // leaf node
			sz = v.size();
		} else { // non leaf node
			sz = v.size();
			mapLeft.resize(sz);
			mapRight.resize(sz);

			mapLeft[0] = v[0] <= mi;
			mapRight[0] = v[0] > mi;

			vector<ll> l, r;

			if (v[0] <= mi) l.push_back(v[0]);
			else r.push_back(v[0]);

			for (int i = 1; i < sz; i++) {
				mapLeft[i] = mapLeft[i-1] + (v[i] <= mi);
				mapRight[i] = mapRight[i-1] + (v[i] > mi);

				if (v[i] <= mi) l.push_back(v[i]);
				else r.push_back(v[i]);
			}

			L = new Wavelet(l);
			R = new Wavelet(r);
		}
	}

	/** frequency of X on interval [0..i] */
	int rank(int x, int i) {
		if (i < 0) return 0;

		if (lo == hi) { // leaf node
			if (x == lo) return i + 1;
			else return 0;
		} else {
			if (x <= mi) return L->rank(x, mapLeft[i] - 1);
			else return R->rank(x, mapRight[i] - 1);
		}
	}

	/** frequency of X on interval [i..j] */
	int rank(int x, int i, int j) {
		return rank(x, j) - rank(x, i - 1);
	}

	/** Find the k-th smallest element in range [i..j] */
	ll kthSmallest(int k, int i, int j) {
		i = max(i, 0); j = max(j, 0);

		if (i > j) return -1; // out of bounds
		if (lo == hi) return lo; // leaf node;

		int qtL = i == 0 ? 0 : mapLeft[i-1];
		int qtR = mapLeft[j];
		int inLeft = qtR - qtL;

		if (k <= inLeft) return L->kthSmallest(k, mapLeft[i] - 1, mapLeft[j] - 1);
		else return R->kthSmallest(k - inLeft, mapRight[i] - 1, mapRight[j] - 1);
	}

	~Wavelet() {
		if (L) delete L;
		if (R) delete R;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, q; cin >> n >> q;
	vector<ll> a(n);
	for (ll& i : a) {
		cin >> i;
		i += 2e9;
	}

	Wavelet T(a);
	while(q--) {
		int k, l, r; cin >> l >> r >> k;
		cout << ll(T.kthSmallest(k, l - 1, r - 1) - 2e9) << '\n';
	}
}