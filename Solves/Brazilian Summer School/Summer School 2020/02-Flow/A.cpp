#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define debug false
#define MAX 

const int N = 4e5 + 5;
int S = N-2, T = N-1;
 
struct edge {
	int a, b, cap, flow;
};
 
int d[N], ptr[N], q[N];
vector<edge> e;
vector<int> g[N];
vector<int> ind;
void add_edge (int a, int b, int cap) {
	edge e1 = { a, b, cap, 0 };
	edge e2 = { b, a, 0, 0 };
	g[a].push_back ((int) e.size());
	e.push_back (e1);
	g[b].push_back ((int) e.size());
	e.push_back (e2);
}
 
bool bfs(int s, int t) {
	int qh=0, qt=0;
	q[qt++] = s;
	memset (d, -1, sizeof d);
	d[s] = 0;
	while (qh < qt && d[t] == -1) {
		int v = q[qh++];
		for (size_t i=0; i<g[v].size(); ++i) {
			int id = g[v][i],
				to = e[id].b;
			if (d[to] == -1 && e[id].flow < e[id].cap) {
				q[qt++] = to;
				d[to] = d[v] + 1;
			}
		}
	}
	return d[t] != -1;
}
 
int dfs (int v, int flow, int t) {
	if (!flow)  return 0;
	if (v == t)  return flow;
	for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
		int id = g[v][ptr[v]],
			to = e[id].b;
		if (d[to] != d[v] + 1)  continue;
		int pushed = dfs (to, min (flow, e[id].cap - e[id].flow), t);
		if (pushed) {
			e[id].flow += pushed;
			e[id^1].flow -= pushed;
			return pushed;
		}
	}
	return 0;
}
 
int dinic(int s, int t) {
	int flow = 0;
	for (;;) {
		if (!bfs(s, t))  break;
		memset (ptr, 0, sizeof ptr);
		while (int pushed = dfs (s, INF, t))
			flow += pushed;
	}
	return flow;
}


int main()
{	
	fastcin;
	int n;	
	cin >> n;
	S = 1;
	T = n;
	int m;
	cin >> m;
	for(int i=0;i<m;i++)
	{	
		int a,b,c;
		cin >> a >> b >> c;
		ind.pb(e.size());
		add_edge(a,b,c);
		add_edge(b,a,c);
	}
	cout << dinic(S,T) << endl;
	for(int i=0;i<e.size();i++)
	{
		if(e[i].flow == 0)
			cout << -e[i+2].flow << endl;
		else
			cout << e[i].flow << endl;
		i+=3;
	}
}