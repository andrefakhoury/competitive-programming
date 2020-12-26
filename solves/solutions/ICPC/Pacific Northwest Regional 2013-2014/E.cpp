#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define MAX 1003
#define debug false
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
map<char,int>custo;
int ini;
int n,m,k;
vector<pair<int,int> > grafo[MAX*MAX];
int convert(int i,int j)
{
    return i*m + j;
}
pair<int,int> volta(int a)
{
    int i = a/m;
    int j = a%m;
    return mp(i,j);
}
int dist[MAX*MAX];
int djikstra(int root)
{
	for(int i=0;i<MAX*MAX;i++)
		dist[i] = INF;
	priority_queue<pair<int,int > > pq;
	dist[root] = 0;
	pq.push(mp(0,root));
	while(pq.size())
	{
		int topo = pq.top().se;
		int peso = -pq.top().fi;
		pq.pop();
        if(debug)
            cout << "at = " << topo << " peso = " << peso << endl;

		if(dist[topo] < peso)
			continue;
		for(int i=0;i<(int)grafo[topo].size();i++)
		{
			int next = grafo[topo][i].se;
			if(dist[next] > dist[topo] + grafo[topo][i].fi)
			{
				dist[next] = dist[topo] + grafo[topo][i].fi;
				pq.push(mp(-dist[next],next));
			}
		}
	}
    int resp = INF;
    for(int i = 0;i<n;i++)
    {
        if(debug)
        {
            cout << dist[convert(i,0)] << " " << dist[convert(i,m-1)]; 
            cout << endl;
        }
        resp = min(dist[convert(i,0)],resp);
        resp = min(dist[convert(i,m-1)],resp);
    }
    for(int j= 0;j<m;j++)
    {
        if(debug)
        {
            cout << dist[convert(0,j)] << " " << dist[convert(n-1,j)] << endl;
        }
        resp = min(resp,dist[convert(0,j)]);
        resp = min(resp,dist[convert(n-1,j)]);
    }
    return resp;
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    string mat[MAX];
    cin >> t;
    while(t--)
    {
        custo.clear();
        cin >> k >> m >> n;
        for(int i=0;i<k;i++)
        {
            char letra;
            int c;
            cin >> letra >> c;
            custo[letra] = c;
        }
        for(int i=0;i<n;i++)
            cin >> mat[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int at = convert(i,j);
                int up,dow,l,r;
                l = convert(i,j-1);
                r = convert(i,j+1);
                dow = convert(i+1,j);
                up = convert(i-1,j);
                if(mat[i][j] == 'E')
                    ini = at;
                if(i!=0)
                {
                    char letra = mat[i-1][j];
                    int cu = custo[letra];
                    grafo[at].pb(mp(cu,up));
                }
                if(i!=n-1)
                {
                    char letra = mat[i+1][j];
                    int cd = custo[letra];
                    grafo[at].pb(mp(cd,dow));
                }
                if(j!=0)
                {
                    char letra = mat[i][j-1];
                    int cl = custo[letra];
                    grafo[at].pb(mp(cl,l));
                }
                if(j!=m-1)
                {
                    char letra = mat[i][j+1];
                    int cr = custo[letra];
                    grafo[at].pb(mp(cr,r));
                }
            }
        }
        if(false)
        {
            for(int i =0;i<m*n;i++)
            {
                for(int j = 0;j<grafo[i].size();j++)
                {
                    cout << "at = " << i << " " << grafo[i][j].se << endl;
                }
                cout << endl;
            }
        }
        if(debug)
            cout << "ini = " << ini << endl;
        cout << djikstra(ini) << "\n"; 
        for(int i = 0;i<n;i++)
            for(int j = 0;j<m;j++)
            {
                int at = convert(i,j);
                grafo[at].clear();
            }
            
    }

    return 0;
}