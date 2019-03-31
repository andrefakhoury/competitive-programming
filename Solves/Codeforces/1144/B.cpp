#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2005;

int a[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	ll sum = 0;

	priority_queue<int> imp, par;

	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) sum += a[i];
	for (int i = 1; i <= n; i++) {
		if (a[i]%2) imp.push(a[i]);
		else par.push(a[i]);
	}

	while (imp.size() && par.size()) {
		imp.pop();
		par.pop();
	}

	if (imp.size()) imp.pop();
	if (par.size()) par.pop();

	ll ans = 0;
	while (imp.size()) {
		ans += imp.top();
		imp.pop();
	}
	while (par.size()) {
		ans += par.top();
		par.pop();
	}

	cout << ans << endl;

	

}