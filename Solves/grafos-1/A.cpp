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

void dfs(int u) {
	vis[u] = 1;
	
	for(int i = 0; i < edges[u].size(); ++i) {
		int v = edges[u][i];
		
		if(vis[v] == 0) dfs(v);
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	
	int N, M, A, B, x, y;
	
	cin >> N >> M >> A >> B;
	
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edges[x].pb(y);
	}
	dfs(A);
	if (vis[B] == 0) cout << "NAO\n";
	else cout << "SIM\n";
	
	
	return 0;
}