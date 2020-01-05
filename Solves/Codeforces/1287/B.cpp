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
const int MAXN = 1500 + 5;
const int MAXK = 30 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline char choose(char a, char b) {
	if (a == b) return a;
	int s = (a == 'S') || (b == 'S');
	int e = (a == 'E') || (b == 'E');
	int t = (a == 'T') || (b == 'T');

	if (!t) return 'T';
	if (!s) return 'S';
	return 'E';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;
	vector<string> a(n);
	for (auto& i : a) cin >> i;

	unordered_map<string, int> mp;
	for (auto& s : a) mp[s]++;

	ll ans = 0;
	string cur;

	for (int i = 0; i < n; i++) {
		mp[a[i]]--;
		for (int j = i+1; j < n; j++) {
			mp[a[j]]--;

			cur.clear();
			for (int t = 0; t < k; t++)
				cur.pb(choose(a[i][t], a[j][t]));

			ans += mp[cur];
		}

		for (int j = i+1; j < n; j++) mp[a[j]]++;
	}

	cout << ans << '\n';


	return 0;
}