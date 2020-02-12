#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) {
		int n; cin >> n;
		vector<int> a(2 * n);
		for (int& i : a) cin >> i;
		sort(a.begin(), a.end());
		cout << a[n]-a[n-1] << '\n';
	}
	

	return 0;
}