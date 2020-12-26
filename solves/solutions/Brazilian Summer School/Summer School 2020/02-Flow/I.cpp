#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define mk make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define endl "\n"
#define debug false
#define MAX 
typedef long long ll ;
#define int long long

typedef pair<int, int> ii;
const double PI = acos(-1.0);

struct edge {
	int to, cost, cap, flow, rid;

	edge () {}

	edge (int a, int b, int c, int d, int e) : 
		to(a), cost(b), cap(c), flow(d), rid(e) {}
};

const int N = 1110;
int S = N-1;
int T = N-2;
vector <edge> g[N];
int n;

void add (int a, int b, int cost, int cap) {
	g[a].pb(edge(b, cost, cap, 0, g[b].size()));
	g[b].pb(edge(a, -cost, 0, 0, g[a].size() - 1));
}

int h[N];
/*negative edges*/
void bellman_ford (int s) {
	fill (h, h + N, INF);
	h[s] = 0;
	for (int i = 0; i < n - 1; i++) 
		for (int at = 0; at < n; at++) 
			for (int j = 0; j < (int)g[at].size(); j++) {
				if (!g[at][j].cap)	continue;
				int next = g[at][j].to, w = g[at][j].cost;
				h[next] = min (h[next], h[at] + w);
			}
}

ii pai[N];
int dist[N];
int dijkstra (int s, int t) {
	fill (dist, dist + N, INF);
	for (int i = 0; i < N; i++)
		pai[i] = ii(-1, -1);
	priority_queue <ii, vector <ii>, greater<ii> > pq;

	dist[s] = 0;
	pq.push(ii(0, s));

	bool ret = false;
	while (pq.size()) {
		int at = pq.top().se;
		int d = pq.top().fi;
		pq.pop();

		if (at == t) 
			ret = true;

		if (d != dist[at])
			continue;

		for (int i = 0; i < (int)g[at].size(); i++) {
			edge edg = g[at][i];
			int next = edg.to;
			if (edg.cap - edg.flow <= 0)	continue;
			ll w = dist[at] + edg.cost + h[at] - h[next];
			if (dist[next] > w) {
				dist[next] = w;
				pai[next] = ii(at, i);
				pq.push(ii(dist[next], next));
			}
		}
	}

	for (int i = 0; i < N; i++)
		if (h[i] < INF and dist[i] < INF)
			h[i] += dist[i];

	return ret;
}

ii max_flow (int s, int t) {
	int cost = 0, flow = 0;
	bellman_ford(s);

	while (dijkstra(s, t)) {
		int f = INF;
		for (int at = t; at != s; at = pai[at].fi) {
			edge edg = g[pai[at].fi][pai[at].se];
			f = min (f, edg.cap - edg.flow);
		}
		flow += f;
		for (int at = t; at != s; at = pai[at].fi) {
			edge &edg = g[pai[at].fi][pai[at].se];
			edg.flow += f;
			g[edg.to][edg.rid].flow -= f;
			cost += edg.cost * f;
		}
	}

	return mk(cost, flow);
}

int resp[N];
int32_t main()
{	
	fastcin;
	int k;		
	cin >> n >> k;
	map<int,int> real;// ID->real
	//map<tuple<int,int,int>,int > volta // tupla -> ID
	vector<tuple<int,int,int,int> > v;
	for(int i=0;i<n;i++)
	{
		int a,b,c;
		cin >> a >> b >> c;
		v.pb(make_tuple(a,a+b-1,c,i));
	}
	sort(v.begin(),v.end());

	add(S,0,0,k); // ligo Source com nó 0
	add(n,T,0,k); // ligo tempo INF com target
	for(int i=0;i<n;i++)
	{
		int ini,fim,profit;
		tie(ini,fim,profit,ignore) = v[i];	
		bool usou = false;
		for(int j=i+1;j<n;j++)
		{
			int a,b,c;
			tie(a,b,c,ignore) = v[j];	
			if(a>fim)
			{
				usou = true;
				add(i,j,-profit,1); // ligação que ganha dinheiro
				break;
			}
		}
		if(!usou)
			add(i,n,-profit,1);
		add(i,i+1,0,k+10);
	}
	max_flow(S,T);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<g[i].size();j++)
		{
			if(g[i][j].cap == 1 and g[i][j].flow == 1)
			{
				int posi;
				tie(ignore,ignore,ignore,posi) = v[i];
				resp[posi] = 1;
			}	
		}
	}
	for(int i=0;i<n;i++)
		cout << resp[i] << " " ;
	cout << endl;
}