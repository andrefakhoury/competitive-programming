#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long
#define endl "\n"
#define MAX
 typedef pair<int, int> pii;
const int maxn = 3605;
 int dist[maxn];
 void bfs(vector<int> const& v) {
    queue<int> q{{0}};
    memset(dist, -1, sizeof(dist));
    dist[0] = 0;
     while (!q.empty()) {
        int at = q.front();
        q.pop();
         for (int i : v) {
            int prox = at + i;
            prox = max(prox, 0);
            prox = min(prox, 3600);
             if (dist[prox] == -1) {
                dist[prox] = dist[at] + 1;
                q.push(prox);
            }
        }
    }
}
 int main() {
 fastcin;
     int T; cin >> T;
    while(T--) {
        int n, t; cin >> n >> t;
        vector<int> tmp(n);
        for (int& i : tmp) cin >> i;
         bfs(tmp);
         for (int i = t; i <= 3600; i++) {
            if (dist[i] != -1) {
                cout << dist[i] << " " << i-t << "\n";
                break;
            }
        }
    }
}