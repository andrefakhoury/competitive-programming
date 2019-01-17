//PORRA TURCI, SO FAZ MERDA

#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back

using namespace std;
typedef pair<int, int> ii;
typedef long long ll;

const int N = 1000007, inf = 0x3f3f3f3f;

vector<int> ind[N];
int a[N];

int ans[N];

void no() {
	cout << "Impossible\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;

	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		ind[a[i]].pb(i);
	}

	int t = 0;
	for(int i = 0; i < n; ++i) {
		if(ind[i].size()) {
			// if(n - i < ind[i].size()) no(1);
			if(ind[i].size()%(n - i)) no();
			for(int j = 0; j < ind[i].size(); ++j) {
				if(j%(n-i) == 0) ++t;
				ans[ind[i][j]] = t;
			}
		}
	}

	for(int i = 0; i < n; ++i) if(ans[i] == 0) no();

	cout << "Possible\n";

	for(int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

}