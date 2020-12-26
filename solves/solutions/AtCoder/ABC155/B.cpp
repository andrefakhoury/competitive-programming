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
	int n; cin >> n;

	bool ans = true;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x%2 == 0) ans &= x%3 == 0 or x%5 == 0; 
	}

	cout << (ans ? "APPROVED" : "DENIED") << '\n';

	return 0;
}