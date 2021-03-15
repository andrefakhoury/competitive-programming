#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 2e5 + 5;

int v[N];
int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;

	while(t--) {
		int n, m; cin >> n >> m;

		for(int i = 0;i < n; ++i) cin >> v[i];

		int last = -1;
		for(int i = 0; i < n; ++i) {
			int &  x = v[i];
			if(x == -1 and last != -1) {
				x = (last + 1)%m;
			}
			last = x;
		}

		last = -1;
		for(int i = n-1; i >= 0; --i) {
			int &  x = v[i];
			if(x == -1 and last != -1) {
				x = (last - 1 + m)%m;
			}
			last = x;
		}

		for(int i = 0; i < n; ++i) cout << v[i] << ' ';
		cout << '\n';
	}

	return 0;
}