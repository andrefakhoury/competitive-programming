#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);	
	
	string s;
	cin >> s;
	int n = s.size();

	int c1 = count(s.begin(), s.end(), '1');
	int c0 = n - c1;

	string ans;
	if (c0 > c1) {
		ans = string(n, '1');
	}
	else if (c0 < c1) {
		ans = string(n, '0');
	}
	else {
		int b = int(s.front() == '0') + int(s.back() == '0');

		if (b == 0) {
			// s[0] = 1 e s[n-1] = 1
			ans = string(n, '1');
			ans[0] = '0';
		}
		else if (b == 2) {
			ans = string(n, '0');
			ans[0] = '1';
		}
		else {
			ans = string(n, '0');
			if (s[0] == '1') ans[n-1] = '1';
			else ans[0] = '1';
		}
	}

	cout << ans << "\n";
	return 0;
}