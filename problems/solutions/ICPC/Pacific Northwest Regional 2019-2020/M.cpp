#include <bits/stdc++.h>
using namespace std;

#define MAX 1005
#define pii pair<int, int>
#define pb push_back
#define ff first
#define ss second

int r, c, ans, vertices;
bool vis[MAX][MAX];
vector<pii> adj[MAX][MAX];

void dfs(int i, int j){
  vis[i][j] = true;
  vertices++;
  for(pii v : adj[i][j])
    if(!vis[v.ff][v.ss])
      dfs(v.ff, v.ss);
}

int main(){
  memset(vis, false, sizeof vis);

  cin>>r>>c;
  for(int i=0; i<r; i++){
    for(int j=0; j<c; j++){
      char m; cin>>m;
      if(m=='\\'){
	adj[i][j].pb({i+1, j+1});
	adj[i+1][j+1].pb({i, j});
      }
      if(m=='/'){
	adj[i][j+1].pb({i+1, j});
	adj[i+1][j].pb({i, j+1});
      }
      if(m!='.') ans++;
    }
  }
  
  for(int i=0; i<=r; i++)
    for(int j=0; j<=c; j++)
      if(!vis[i][j]){
	vertices = 0;
	dfs(i, j);
	ans-=vertices-1;
      }
  
  cout<<ans<<"\n";
  
  return 0;
}
