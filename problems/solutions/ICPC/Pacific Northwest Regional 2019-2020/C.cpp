#include<bits/stdc++.h>
using namespace std;

#define MAX 100005
#define pb push_back

int n, m;
vector<int> adj[MAX];

int dist[MAX];

void bfs(int s){
  memset(dist, -1, sizeof(dist));
  queue<int> q;
  q.push(s);
  dist[s] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    for(int v : adj[u]){
      if(dist[v] == -1){
	dist[v] = dist[u]+1;
	q.push(v);
      }
    }
  }
}

int main(){

  cin>>n>>m;
  for(int i=0; i<m; i++){
    int a, b; cin>>a>>b;
    adj[a].pb(b);
    adj[b].pb(a);
  }
  bfs(1);
  cout<<dist[n]-1<<"\n";

  return 0;
}
