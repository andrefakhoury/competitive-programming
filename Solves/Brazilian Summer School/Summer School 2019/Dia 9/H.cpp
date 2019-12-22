#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	int n, q; scanf("%d%d", &n, &q);
	vector<int> a(n);
	map<int, ord_set<int> > h;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		h[a[i]].insert(i);
	}

	int ind, typ, ans, old;
	while(q--) {
		scanf("%d%d", &ind, &typ);

		old = a[ind];
		h[old].erase(ind);
		a[ind] = typ;

		h[typ].insert(ind);

		ans = h[typ].order_of_key(ind);
		printf("%d\n", ans);
	}
}