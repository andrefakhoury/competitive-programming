#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1005;

#define MOD 1000000007LL
int a[MAXN];
int n;

int solve(int m) {
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		cur += a[i] * abs(m - i);
		cur += a[i] * abs(i - 1);
		cur += a[i] * abs(1 - m);

		cur += a[i] * abs(m - 1);
		cur += a[i] * abs(1 - i);
		cur += a[i] * abs(i - m);
	}
	return cur;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int ans = solve(1);
	for (int i = 2; i <= n; i++) 
		ans = min(ans, solve(i));

	cout << ans << endl;	
	return 0;
}