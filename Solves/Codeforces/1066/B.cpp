#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
int n, r, a[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> r;
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = 0, last = -1;
	while (last < n - 1) {
		int pos = -1;
		for (int i = n - 1; i > max(-1, last - r + 1); i--) {
			if (a[i] == 1 && i - r <= last) {
				pos = i;
				break;
			}
		}
		
		if (pos == -1) {
			cout << -1 << "\n";
			return 0;
		}
		
		ans++;
		last = pos + r - 1;
	}
	
	cout << ans << endl;
}