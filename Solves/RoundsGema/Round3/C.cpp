#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAX 200010
#define MAXM 100005

#define TAMX (int)edges[x].size()-1
#define TAMY (int)edges[y].size()-1

//ios::sync_with_stdio(false);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int id[MAX], nodes, m;
pair <long long, pair<int, int> > p[MAX];
vector<int> edges[MAX];
int vis[MAX];

void initialize() {
    for(int i = 0;i < MAX;++i)
        id[i] = i;
}

int root(int x) {
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y) {
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

long long kruskal(pair<long long, pair<int, int> > p[]) {
    int x, y;
    long long cost, minimumCost = 0;
    for(int i = 0;i < m;++i)
    {
        // Selecting m one by one in increasing order from the beginning
        x = p[i].second.first;
        y = p[i].second.second;
        cost = p[i].first;
        // Check if the selected edge is creating a cycle or not
        if(root(x) != root(y))
        {
            minimumCost += cost;
            union1(x, y);
        }    
    }
    return minimumCost;
}

void dfs(int u) {
	vis[u] = 1;
	for(int i = 0; i < (int)edges[u].size(); ++i) {
		if(vis[edges[u][i]] == 0) dfs(edges[u][i]);
	}
}

int main() {
    int x, y;
    long long weight, cost, minimumCost;
    initialize();
    cin >> nodes >> m;
    for(int i = 0;i < m;++i)
    {
        cin >> x >> y >> weight;
        edges[x].pb(y);
        edges[y].pb(x);
        p[i] = mp(weight, mp(x, y));
    }
    
    dfs(1);
    for (int i = 1; i <= nodes; i++) {
		if (!vis[i]) return !printf("-1\n");
	}
    
    sort(p, p + m);
    minimumCost = kruskal(p);
    cout << minimumCost << endl;
    return 0;
}