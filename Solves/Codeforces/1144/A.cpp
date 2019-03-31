#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int t; cin >> t;

	while (t--) {
		string s; cin >> s;
		sort(s.begin(), s.end());

		bool flag = true;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i-1] + 1) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

}