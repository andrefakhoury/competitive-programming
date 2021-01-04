#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define long long ll;
#define debug false
typedef pair<int, int> pii;

const int MAX = 2003;

vector<pair<int,int > > grafo[MAX];
int dists[MAX],distg[MAX],disth[MAX];

void djikstra(int root,int op)
{
	int dist[MAX];
	for(int i=0;i<MAX;i++)
		dist[i] = INF;
	priority_queue<pair<int,int > > pq;
	dist[root] = 0;
	pq.push(mp(0,root));
	while(pq.size())
	{
		int topo = pq.top().se;
		int peso = -pq.top().fi;
		pq.pop();
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
	if(op == 0) // sai do s
		for(int i=0;i<MAX;i++)
			dists[i] = dist[i];
	if(op == 1) // sai do g
		for(int i=0;i<MAX;i++)
			distg[i] = dist[i];
	if(op == 2) // sai do h
		for(int i=0;i<MAX;i++)
			disth[i] = dist[i];
}

int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	vector<int> possfim;
	while(t--)
	{
		int esp;
		int n,m,t;	
		int s,g,h;
		possfim.clear();
		cin >> n >> m >> t;
		cin >> s >> g >> h;
		// start, g e h nós do cheiro
		s--;
		g--;
		h--;
		for(int i=0;i<n;i++)
			grafo[i].clear();	

		for(int i=0;i<m;i++)
		{
			int a, b,c;
			cin >> a >> b >> c;
			a--;
			b--;
			if(( a == g and b == h) or( a == h and b == g))
				esp = c;
			grafo[a].pb(mp(c,b));
			grafo[b].pb(mp(c,a));
		}	
		for(int i=0;i<t;i++)
		{
			int x; // possivel fim
			cin >> x;
			x--;
			possfim.pb(x);
		}
		djikstra(s,0);
		djikstra(g,1);
		djikstra(h,2);
		vector<int> resp;
		if(debug)
			cout << "disth = " << dists[h] << " " << dists[g] << endl; 
		for(int i=0;i<t;i++)
		{
			int r = possfim[i];
			
			int op1 = dists[g] + esp + disth[r];
			int op2 = dists[h] + esp + distg[r];
			if(debug)
				cout << "op de fim = " << r << " dists = " << dists[r] << " op1 = " << op1 << " op2 = " << op2 << endl;

			if(dists[r] == op1 or dists[r] == op2)
				resp.pb(r);
		}
		sort(resp.begin(),resp.end());
		for(int i=0;i<resp.size();i++)
			cout << resp[i] +1 << " " ;
		cout << endl;
	}
	return 0;
}