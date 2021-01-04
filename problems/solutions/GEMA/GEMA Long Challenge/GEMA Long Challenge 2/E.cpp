#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e6 + 5;
vector<int> ind[MAXN];
vector<int> vec;

int find(int x, int l, int r) {
	return upper_bound(ind[x].begin(), ind[x].end(), r) -
		   lower_bound(ind[x].begin(), ind[x].end(), l);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int q; cin >> q;

	while(q--) {
		int op; cin >> op;

		if (op == 1) {
			int x; cin >> x;
			vec.push_back(x);
			ind[x].push_back(vec.size());
		} else if (op == 0) {
			if (vec.size() == 0) {
				cout << "invalid\n";
				continue;
			}

			int x = vec.back();
			ind[x].pop_back();
			vec.pop_back();
		} else {
			int x, i, j; cin >> x >> i >> j;
			cout << find(x, i, j) << '\n';
		}
	}
}