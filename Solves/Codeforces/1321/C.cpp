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

inline bool can(string& s, int i) {
	if (i > 0 && s[i-1] == s[i]-1) return true;
	if (i < (int)s.size() - 1 && s[i+1] == s[i]-1) return true;
	return false;
}

int solve(string& s) {
	int ans = 0;
	while(s.size()) {
		bool ok = false;

		int ind = -1;
		for (int i = 0; i < (int)s.size(); i++)
			if (can(s, i) && (ind == -1 || s[i] > s[ind])) ind = i;
		if (ind != -1) {
			s.erase(ind, 1);
			ans++;
		} else break;
	}
	return ans;	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	string s; cin >> s;
	cout << solve(s) << '\n';
	return 0;
}