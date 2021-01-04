#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update>;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 2e5 + 5;

pii a[MAXN];

vector<int> ini[MAXN], fim[MAXN];

int main() {
	int n; scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &a[i].fi, &a[i].se);
		ini[a[i].fi].eb(i);
		fim[a[i].se].eb(i);
	}

	ord_set<int> st;
	for (int k = 1; k <= n; k++) {
		for (int i : ini[k]) st.insert(i);
		auto it = st.find_by_order(k-1);
		if (it == st.end()) {
			printf("-1 ");
		} else {
			printf("%d ", *it);
		}

		for (int i : fim[k]) st.erase(i);
	}
	printf("\n");


}