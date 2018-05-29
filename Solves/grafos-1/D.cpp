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

const int N = 100005;

vector<int> edges[N];
int dist[N];

void bfs(int s) {
    memset(dist, -1, sizeof dist);
    queue<int> q;

    dist[s] = 0;
    q.push(s);

    while(q.size()) {
        int u = q.front();
        q.pop();
        
        for(int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if(dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(void) {
	ios::sync_with_stdio(false);
	
	int Z, M, A, B, x, y;
	cin >> Z >> M >> A >> B;
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		edges[x].pb(y);
		edges[y].pb(x);
	}
	bfs(A);
	
	cout << dist[B] << endl;
	
	return 0;
}