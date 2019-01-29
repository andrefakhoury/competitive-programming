#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

int memo[MAXN];
bool check(string& s, int k, int n) {
	int jump = __gcd(k, n);
	if (memo[jump] != -1) return memo[jump];

	for (int i = 0; i < n; i++) {
		if (s[i] == 'P') continue;
		bool flag = false;
		for (int j = (i+jump)%n; j != i; j = (j + jump)%n) {
			if (s[j] == 'P') {
				flag = true;
				break;
			}
		}
		if (flag == false) return memo[jump] = true;
	}
	return memo[jump] = false;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	string s;

	while(cin >> s) {
		int n = s.size();
		int sub = 0, cur = 0;
		for (int i = 0; i < 2 * n; i++) {
			int pos = i%n;
			if (s[pos] == 'P') cur++;
			else cur = 0;

			sub = max(sub, cur);
		}

		memset(memo, -1, sizeof memo);

		int ans = 0;
		for (int i = 1; i < n; i++) ans += check(s, i, n);

		cout << ans << "\n";
	}
	
	return 0;
}
