#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 200010;

ll b[MAXN];
ll a[2 * MAXN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	for (int i = 1; i <= n/2; i++) cin >> b[i];

	a[n+1] = LLONG_MAX;
	a[0] = 0;

	for (int i = 1; i <= n/2; i++) {
		a[i] = a[i-1];
		a[n-i+1] = b[i] - a[i];

		if (a[n-i+1] > a[n-i+2]) {
			a[i] += a[n-i+1] - a[n-i+2];
			a[n-i+1] = b[i] - a[i];
		}
	}

	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	cout << endl;

	return 0;
}