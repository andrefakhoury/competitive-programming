#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	map<int, int> freq;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		freq[x]++;
	}

	long long ans = 0;

	int cur = freq[0];
	for (int i = cur; i > 1; i--) ans += i - 1;

	for (int i = -10; i < 0; i++) {
		for (int j = freq[i]; j > 0; j--) {
			ans += freq[-i];
		}
	}

	cout << ans << endl;
}