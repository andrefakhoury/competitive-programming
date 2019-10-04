#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update>;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string s; cin >> s;

	ord_set<int> pos[26];
	for (int i = 0; i < (int)s.size(); i++) {
		pos[s[i]-'a'].insert(i + 1);
	}

	int q; cin >> q;
	while(q--) {
		int t; cin >> t;
		if (t == 2) {
			int l, r; cin >> l >> r;
			int ans = 0;

			for (int i = 0; i < 26; i++) {
				int cur = 0;
				cur += pos[i].order_of_key(r+1);
				cur -= pos[i].order_of_key(l);

				if (cur) ans++;
			}

			cout << ans << '\n';
		} else {
			int i; cin >> i;
			char c; cin >> c;
			pos[s[i-1]-'a'].erase(i);
			s[i-1] = c;
			pos[s[i-1]-'a'].insert(i);
		}

	}

	return 0;
}