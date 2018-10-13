#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int main() {
	ios::sync_with_stdio(false);
	int n; cin >> n;
	char a[MAXN], b[MAXN]; cin >> a+1 >> b+1;
	int ans = 0;

	if (n%2 && a[n/2+1] != b[n/2+1]) ans++;

	for (int i = 1; i <= n/2; i++) {
		int j = n-i+1;

		if (a[i] == b[i] && a[j] == b[j]) continue;
		else if (a[i] == b[j] && a[j] == b[i]) continue;
		else if (a[i] == a[j] && b[i] == b[j]) continue;
        else if (a[i] == b[i]) ans++;
        else if (a[i] == b[j]) ans++;
        else if (a[j] == b[i]) ans++;
        else if (a[j] == b[j]) ans++;
        else if (b[i] == b[j]) ans++;
        else ans += 2;	
	}

	cout << ans << endl;
}
