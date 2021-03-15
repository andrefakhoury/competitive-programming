#include <bits/stdc++.h>

#define pb push_back
#define fi first

using namespace std;
typedef long long ll;

const int N = 100007;

vector<int> e[N];

int vis[N];
int lev[N];
int pai[N];

vector<int> U;
void dfs(int u, int l = 0) {
    vis[u] = 1;
    lev[u] = l;

    U.pb(u);

    for(int v : e[u]) {
        if(vis[v] == 0) {
            dfs(v, l + 1);
            pai[v] = u;        
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, l; cin >> n >> l;

    for(int i = 0; i < l; ++i) {
        int u, v; cin >> u >> v;
        e[u].pb(v);
        e[v].pb(u);
    }

    vector<int> centers;
    for(int i = 0; i < n; ++i) {
        if(vis[i] == 0) {
            // resolve tree
            dfs(i);
            int r = i;
            for(int u : U) {
                if(lev[u] > lev[r]) r = u;
            }

            for(int u : U) {
                vis[u] = lev[u] = pai[u] = 0;
            }
            U.clear();
            dfs(r);

            int v = i;
            for(int u : U) {
                if(lev[u] > lev[v]) v = u;
            }

            vector<int> path;
            int cnt = 0;
            for(int u = v; u != r; u = pai[u]) {
                cnt++;
            }
            centers.pb(cnt);

            for(int u : U) {
                lev[u] = pai[u] = 0;
            }
            U.clear();
        }
    }

    sort(centers.rbegin(), centers.rend());
    if(centers.size() < 2) {
        cout << centers[0] << endl;
    } else if(centers.size() < 3) {
        cout << max(centers[0], (centers[1] + 1)/2 + 1 + (centers[0] + 1)/2) << endl;
    } else {
        cout << max({centers[0], (centers[1] + 1)/2 + 1 + (centers[0] + 1)/2, (centers[2] + 1)/2 + 1  + (centers[1] + 1)/2 + 1 }) << endl;
    }
}