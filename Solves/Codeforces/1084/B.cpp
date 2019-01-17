#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1005;

int v[MAXN];
int n;

bool check(int k, ll s) {
	ll cur = 0;
	for (int i = 1; i <= n; i++) {
		if (v[i] < k) return false;
		if (v[i] == k) continue;

		cur += v[i]-k;

		if (cur >= s) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	ll s, sum = 0;

	cin >> n >> s;
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		sum += v[i];
	}

	int mini = v[1];
	for (int i = 2; i <= n; i++) mini = min(mini, v[i]);

	if (sum < s) {
		cout << -1 << endl;
		return 0;
	}

	if (sum == s) {
		cout << 0 << endl;
		return 0;
	}

	int lo = 0;
	int hi = mini+1;
	int mid, ans;
	while (lo < hi) {
		mid = (lo+hi)/2;

		if (check(mid, s)){
			ans = mid;
			lo = mid+1;
		}
		else hi = mid;
	}

	cout << ans << endl;
	return 0;
}