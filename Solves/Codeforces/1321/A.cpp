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
	vector<int> a(n), b(n);
	for (int& i : a) cin >> i;
	for (int& i : b) cin >> i;

	int ja = 0, jb = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] && !b[i]) ja++;
		if (!a[i] && b[i]) jb++;
	}

	int ans = 0;
	if (!ja) ans = -1;
	else if (ja > jb) ans = 1;
	else if (ja <= jb) ans = (jb + ja) / ja;

	cout << ans << '\n';

	return 0;
}