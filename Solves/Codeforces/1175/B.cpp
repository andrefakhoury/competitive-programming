#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const ll MAX = (1ll << 32) - 1;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	stack<pair<ll, bool> > st;
	string s;

	ll x = 0, ratio = 1;

	bool care = false;

	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s;

		if (s == "end") {
			care = st.top().se;
			ratio = st.top().fi;
			st.pop();
		} else if (s == "for") {
			ll k; cin >> k;
			st.push(mp(ratio, care));
			ratio = ratio * k;
			
			if (ratio > MAX) {
				ratio = -1;
				care = true;
			}
		} else if (s == "add") {
			if (care) {
				cout << "OVERFLOW!!!" << endl;
				return 0;
			} else {
				x += ratio;
				if (x > MAX) {
					cout << "OVERFLOW!!!" << endl;
					return 0;
				}
			}
		}
	}

	cout << x << endl;
	
	return 0;
}