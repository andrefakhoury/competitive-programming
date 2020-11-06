#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
#define DBG(x) cout << "[" << #x << "]: " << x << endl
using ll = long long;
using pii = pair<int, int>;

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;
	int d;

	while(cin >> s >> d) {
		int n = s.size();

		vector<vector<bool>> memo(n + 1, vector<bool>(d, false));
		vector<vector<int>> dig(n + 1, vector<int>(d, -1));

		memo[n][0] = true;
		for (int i = n - 1; i >= 0; i--) {
			for (int r = 0; r < d; r++) {
				auto go = [&](int k) {
					if (memo[i+1][(r * 10 + k) % d]) {
						memo[i][r] = true;
						dig[i][r] = k;
						return true;
					}

					return false;
				};

				if (s[i] != '?') {
					go(s[i] - '0');
				} else for (int k = 9; k >= 0; k--) if (i != 0 || k != 0)
					go(k);
			}
		}

		if (memo[0][0]) {
			string ans;
			for (int i = 0, r = 0; i < n; i++) {
				ans += dig[i][r] + '0';
				r = (10 * r + dig[i][r]) % d;
			}
			cout << ans << "\n";
		} else {
			cout << "*\n";
		}

	}
}