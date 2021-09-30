#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cout << #x << ": " << x << endl)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 7;
int h[N];
int nxt[N][2];

int cur[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}

	for(int i = 0; i < n; i++) {
		int & j = nxt[i][0];
		for(j = i-1; j >= 0 and h[j] < h[i]; j = nxt[j][0]) {
			// deb(j);
		}
	}

	
	for(int i = n-1; i >= 0; i--) {
		int & j = nxt[i][1];
		// deb(j);
		for(j = i+1; j < n and h[j] < h[i]; j = nxt[j][1]) {
			// deb(j);
		}
	}

	for(int i = 0; i < n; i++) {
		// quanto eu contribuo pra direita
		int r = nxt[i][1];
		int d = r == n? n - i : (r - i - 1)/2;
		if(d) {
			cur[i+1]++;
			cur[i + d + 1]--;
		}

		int l = nxt[i][0];
		d = l == -1? i : (i - l - 1)/2;
		if(d) {
			cur[i]--;
			cur[i - d]++;
		}
	}

	// auto get= [&](int i, int k) {
	// 	if(k == 0) {
	// 		if(i < 0) return 0;
	// 		return f[i][0] + 1;
	// 	} else {
	// 		if(i >= n) return 0;
	// 		return f[i][1] + 1;
	// 	}
	// };

	// for(int i = 0; i < n; i++) {
	// 	f[i][0] = get(nxt[i][0], 0);
	// }
	// for(int i = n-1; i >= 0; i--) {
	// 	f[i][1] = get(nxt[i][1], 1);
	// }

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans += cur[i];
		cout << ans << ' ';
	}
	cout << '\n';
}