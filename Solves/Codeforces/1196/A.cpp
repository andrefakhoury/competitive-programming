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

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		ll a, b, c; cin >> a >> b >> c;
		vector<ll> j = {a, b, c};
		sort(j.begin(), j.end());
		a = j[0];
		b = j[1];
		c = j[2];

		ll qt = b - a;
		if (c >= qt) {
			a += qt;
			c -= qt;
		} else {
			a += c;
			c = 0;
		}

		a += c/2;

		cout << a << '\n';
	}
	
	return 0;
}