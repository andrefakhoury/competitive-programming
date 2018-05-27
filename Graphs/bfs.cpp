vector<int> edges[N];
int dist[N];

void bfs(int s) { //O(V+A)
    memset(dist, -1, sizeof dist);
    queue<int> q;
    dist[s] = 0;
    q.push(s);

    while(q.size()) {
        int u = q.front();
        q.pop();
        for(int i = 0; i < edges[u].size(); ++i) {
            int v = edges[u][i];
            if(dist[v] == -1) { //index not visited
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}
