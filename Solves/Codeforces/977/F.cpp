#include <bits/stdc++.h>
using namespace std;

#define MAXN 200010
#define pb push_back

map<int, int> pos;
int a[MAXN];

vector<int> edges[MAXN];
bool vis[MAXN];
int prox[MAXN];

int ab;
int dfs(int u) {
    vis[u] = true;
    int ret = 0;
    for (int i = 0; i < (int)edges[u].size(); i++) {
        if (!vis[edges[u][i]]) {
            ab = dfs(edges[u][i]);
            if (ab > ret) {
                ret = ab;
                prox[u] = edges[u][i];
            }
        }
    }
    return 1+ret;
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a+i);
        pos[a[i]] = i;
        
        if (pos[a[i]-1]) {
            edges[pos[a[i]-1]].pb(i);
            edges[i].pb(pos[a[i]-1]);
        }
    }
    
    int ans = 0, ind = -1, ret;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            ret = dfs(i);
            if (ret > ans) {
                ans = ret;
                ind = i;
            }
        }
    }
    
    printf("%d\n", ans);
    for (int qt = 0; qt < ans; qt++) {
        printf("%d ", ind);
        ind = prox[ind];
    }
    printf("\n");
    
    printf("\n");
}