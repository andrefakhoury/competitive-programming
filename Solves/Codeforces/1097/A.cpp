#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n = 5;
	string t; cin >> t;
	string h[10];
	for (int i = 1; i <= n; i++) cin >> h[i];

	for (int i = 1; i <= n; i++)
		if (h[i][0] == t[0]) {
			cout << "YES\n";
			return 0;
		}
	for (int i = 1; i <= n; i++)
		if (h[i][1] == t[1]) {
			cout << "YES\n";
			return 0;
		}

	cout << "NO\n";


	return 0;
}