#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define FF first
#define SS second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2e5 + 5;

int a[MAXN];
int freq[MAXN];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int i = 1; i <= n; i++) {
		freq[a[i]]++;
		if (freq[a[i]] == 3) {
			cout << "NO\n";
			return 0;
		}

	}

	vector<int> inc, dec;
	sort(a+1, a+n+1);
	a[0] = -10;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i-1]) dec.pb(a[i]);
		else inc.pb(a[i]);
	}

	sort(dec.begin(), dec.end(), greater<int>());

	cout << "YES\n" << inc.size() << "\n";
	for (int i = 0; i < (int)inc.size(); i++) cout << inc[i] << " ";
	cout << "\n" << dec.size() << "\n";
	for (int i = 0; i < (int)dec.size(); i++) cout << dec[i] << " ";
	cout << "\n";	
}