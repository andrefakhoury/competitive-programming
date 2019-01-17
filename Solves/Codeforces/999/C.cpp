#include <bits/stdc++.h>

using namespace std;
#define MAXN 400025
#define pb push_back

int nope[MAXN];
vector<int> pos[30];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, k; cin >> n >> k;
	string s; cin >> s;
	for (int i = 0; i < n; i++)
		pos[s[i]-"a"].pb(i);
	int cont = 0;
	
	for (int i = 0; i < 26 && cont < k; i++) {
	    for (int j = 0; j < (int)pos[i].size(); j++) {
	        nope[pos[i][j]]++; cont++; if (cont >= k) break;
	    }
	}
	
	for (int i = 0; i < n; i++) {
	    if (!nope[i]) cout << s[i];
	}
	
	cout << "\n";
}