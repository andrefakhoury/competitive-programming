#include <bits/stdc++.h>
 #define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define INF 0x3f3f3f3f
 using namespace std;
 typedef long long ll;
typedef pair<int, int> ii;
 const int N = 2800;
const int S = N-2, T = N-1;
 struct edge {
 int a, b, cap, flow;
};
 int d[N], ptr[N], q[N];
vector<edge> e;
vector<int> g[N];
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
 int const maxn = 32;
char v[maxn][maxn];
 void reset() {
    memset(v, 0, sizeof(v));
    memset(d, 0, sizeof(d));
    memset(ptr, 0, sizeof(ptr));
    memset(q, 0, sizeof(q));
    e.clear();
    for (auto& i : g) i.clear();
}
 int const i_offset = 900;
int const n_offset = 1800;
int main (void) {
    ios_base::sync_with_stdio(false);
        string s;
    while (getline(cin, s)) {
        reset();
         copy(s.begin(), s.end(), v[0]);
        int m = s.size();
        int n = 1;
        while (getline(cin, s)) {
            if (s == ""s) break;
            copy(s.begin(), s.end(), v[n++]);
        }
         auto get_val = [&] (int x, int y) {
            return m*x + y;
        };
         auto add_con = [&] (int offset, char k, int i, int j, int ni, int nj) {
            if (ni < n and nj < m and ni >= 0 and nj >= 0) {
                if (v[ni][nj] == k) {
                    add_edge(get_val(i, j), get_val(ni, nj) + offset, 1);
                }
            }
        };
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'W') {
                    add_edge(S, get_val(i, j), 1);
                     add_con(i_offset, 'I', i, j, i+1, j);
                    add_con(i_offset, 'I', i, j, i, j-1);
                    add_con(i_offset, 'I', i, j, i-1, j);
                    add_con(i_offset, 'I', i, j, i, j+1);
                } 
            }
        }
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'I') {
                    add_edge(get_val(i, j) + i_offset, get_val(i, j), 1);
                     add_con(n_offset, 'N', i, j, i+1, j);
                    add_con(n_offset, 'N', i, j, i, j-1);
                    add_con(n_offset, 'N', i, j, i-1, j);
                    add_con(n_offset, 'N', i, j, i, j+1);
                } 
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (v[i][j] == 'N') {
                    add_edge(get_val(i, j) + n_offset, get_val(i, j), 1);
                    add_edge(get_val(i, j), T, 1);
                } 
            }
        }
         int ans = dinic(S, T);
        cout << ans << "\n";
    }
 return 0;
}