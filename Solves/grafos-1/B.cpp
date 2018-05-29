#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl
#define pow2(x) ((x)*(x))
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;

vector<int> edges[100005];
int vis[100005]; // 0 -> nao visitado, 1 -> visitado
int ans = 0;

void tp(int u) {
	vis[u] = 1;
	
	for(int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		if(vis[v] == 0) tp(v);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	
	int N, M, x, y;
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edges[x].pb(y);
		edges[y].pb(x);
	}
	
	for (int i = 1; i <= N; i++) {
		if (vis[i] == 0) {
			tp(i);
			ans++;
		} 
	}
	
	cout << ans << endl;
	
	return 0;
}