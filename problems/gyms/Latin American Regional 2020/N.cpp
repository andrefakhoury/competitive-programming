#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define deb(x) (cout << #x << ": " << x << endl)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n; scanf("%d ", &n);

	int tot = 0;
	int ans = 0;
	int aux;
	scanf("$%d.%d ", &aux, &tot);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("$%d.%2d ", &x, &y);
		// deb(x);
		// deb(y);

		tot += y;
		tot %= 100;
		if(tot%100) {
			ans++;
		}
	}

	cout << ans << '\n';


}