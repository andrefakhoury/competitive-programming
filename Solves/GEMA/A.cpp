#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int N, M;
ll l, r;

string::size_type sz = 0;

ll solve(int n, int m, string cur) {
	sz = 0;

	if (cur.size() && stoll(cur, &sz, 0) > r) return 0;

	// cout << n << " " << m << " " << cur << endl;
	
	ll ret = 0;
	if (cur.size() && n == N or m == M) ret += stoll(cur, &sz, 0) >= l && stoll(cur, &sz, 0) <= r;

	for (char i = '0'; i <= '9'; i++) {
		if (i == '0' && cur.size() == 0) continue;

		int nc = n + (i-'0' == 4);
		int mc = m + (i-'0' == 7);
		ret += solve(nc, mc, cur + i);
	}

	return ret;
}

int main() {
	cin >> N >> M >> l >> r;
	cout << solve(0, 0, "") << endl;
}