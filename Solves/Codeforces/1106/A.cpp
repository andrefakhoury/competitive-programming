#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
char g[510][510];

bool isG(char c) {
	return c == 'X';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> g[i][j];
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			ans += isG(g[i][j]) && isG(g[i-1][j-1]) && isG(g[i-1][j+1]) && isG(g[i+1][j-1]) && isG(g[i+1][j+1]);
		}
	}
	
	cout << ans << endl;
	
	return 0;
}