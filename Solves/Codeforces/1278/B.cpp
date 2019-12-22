// desisto disso

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-7;
const int MAXN = 2e5 + 5;

vector<ll> sums;
int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int T; cin >> T;
	while(T--) {
		ll a, b; cin >> a >> b;

		if (a > b) swap(a, b);

		for (ll x = 0;; x++) {
			ll sum = x*(x+1)/2;
			if (sum >= b - a && (sum+a+b)%2 == 0) {
				cout << x << '\n';
				break;
			}
		}
	}
}