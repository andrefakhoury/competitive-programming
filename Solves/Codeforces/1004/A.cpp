#include <bits/stdc++.h>
using namespace std;

#define pb push_back

int hot[105];

int main () {
	ios::sync_with_stdio(false);
	int n, d, x; cin >> n >> d;
	
	for (int i = 1; i <= n; i++) cin >> hot[i];

	int ans = 2;
	for (int i = 1; i <= n; i++) {
		if (i > 1 && hot[i]-d > hot[i-1]+d) ans++;
		if (i < n && hot[i]+d <= hot[i+1]-d) ans++;
	}
	cout << ans << endl;
	

}