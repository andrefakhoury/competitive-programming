#include <bits/stdc++.h>
using namespace std;
 #define INF 0x3f3f3f3f
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define debug false
typedef pair<int, int> pii;
 const int MAX = 20013;
 vector<pair<int,int > > grafo[MAX];
ll int dists[MAX],distg[MAX],disth[MAX];
 void djikstra(int root,int op)
{
  if(debug)
  cout << "djikstra = " << op << endl;
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
  if(debug)
   cout << "no atual = " << topo << " dist = " << dist[topo] <<  endl;
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
int S = MAX -1;
int n,m;
int convert(int i, int j)
{
 return i*m + j;
}
int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t;
 cin >> t;
 string str[MAX],mat[MAX];
 while(t--)
 {
  int g=-1,h=-1;
  cin >> n >> m;
  for(int i=0;i<n;i++)
  {
   cin >> str[i];
   mat[i] = str[i];
  }
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<m;j++)
   {
    int at = convert(i,j);
    grafo[at].clear();
   }
  }
  grafo[S].clear();
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<m;j++)
   {
    char at = str[i][j]; 
    int posi = convert(i,j);
    int c = 0;
    if(at == '$' and g == -1)
    {
     g = convert(i,j);
    }
    else if(at == '$')
     h = convert(i,j);
     if(at == '*')
     continue;
     if(i>0 and (str[i-1][j] == '.' or str[i-1][j] == '$') )
     grafo[posi].pb(mp(c,convert(i-1,j)));
    if(i>0 and str[i-1][j] == '#')
     grafo[posi].pb(mp(1,convert(i-1,j)));
     if(i<(n-1) and (str[i+1][j] == '.' or str[i+1][j] == '$') )
     grafo[posi].pb(mp(c,convert(i+1,j)));
    if(i<(n-1) and str[i+1][j] == '#')
     grafo[posi].pb(mp(1,convert(i+1,j)));
     if(j>0 and (str[i][j-1] == '.' or str[i][j-1] == '$') )  
     grafo[posi].pb(mp(c,convert(i,j-1)));
    if(j>0 and str[i][j-1] == '#')
     grafo[posi].pb(mp(1,convert(i,j-1)));
     if(j<(m-1) and (str[i][j+1] == '.' or str[i][j+1] == '$')) 
     grafo[posi].pb(mp(c,convert(i,j+1)));
    if(j<(m-1) and str[i][j+1] == '#')
     grafo[posi].pb(mp(1,convert(i,j+1)));
   }
  }
  for(int i=0;i<n;i++)
  {
   int j1=0,j2 = m-1; 
   if(mat[i][j1] == '.' or str[i][j1] == '$')
   {
    int at = convert(i,j1);
    grafo[S].pb(mp(0,at));
   }
   else if(mat[i][j1] == '#')
   {
    int at = convert(i,j1);
    grafo[S].pb(mp(1,at));
   }
   if(mat[i][j2] == '.' or str[i][j2] == '$' )
   {
    int at = convert(i,j2);
    grafo[S].pb(mp(0,at));
   }
   else if(mat[i][j2] == '#')
   {
    int at = convert(i,j2);
    grafo[S].pb(mp(1,at));
   }
  }
  for(int j=0;j<m;j++)
  {
   int i1=0,i2 = n-1; 
   if(mat[i1][j] == '.' or str[i1][j] == '$')
   {
    int at = convert(i1,j);
    grafo[S].pb(mp(0,at));
   }
   else if(mat[i1][j] == '#')
   {
    int at = convert(i1,j);
    grafo[S].pb(mp(1,at));
   }
   if(mat[i2][j] == '.' or str[i2][j] == '$')
   {
    int at = convert(i2,j);
    grafo[S].pb(mp(0,at));
   }
   else if(mat[i2][j] == '#')
   {
    int at = convert(i2,j);
    grafo[S].pb(mp(1,at));
   }
  }
  djikstra(S,0);
  djikstra(g,1);
  djikstra(h,2);
  ll int resp = INF;
  int posim;
  for(int i=0;i<n;i++)
  {
   for(int j=0;j<m;j++)
   {
    ll int at = convert(i,j);
        if(debug)
    {
     cout << str[i][j]<< endl;
     cout << " at = " << at << "dists = " << dists[at] << " distg = " << distg[at] << " disth = " << disth[at] << endl; 
    }
    ll int respat = dists[at] + distg[at] + disth[at];
        if(str[i][j] == '#')
     respat-=2;
    if(respat < resp)
     posim = convert(i,j);
    resp = min(resp,respat);
   }
  }
  if(debug)
   cout << posim << endl;
  cout << resp << endl;
 }
 return 0;
}