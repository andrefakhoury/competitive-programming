#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL_PC
    #define debug(args...) cout.flush(); fflush(stdout); fprintf(stderr, args)
#else
    #define debug(args...) ; /*  */
#endif
#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> pii;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class num> inline void rd(num &x) {
    char c; while(isspace(c = getchar()));
    bool neg = false;
    if(!isdigit(c)) neg = (c == '-'), x = 0;
    else x = c - '0';
    while(isdigit(c = getchar()))
    x = (x << 3) + (x << 1) + c - '0';
    if (neg) x = -x;
}
template <class T, class... Args> inline void rd(T& x, Args&... args) { rd(x); rd(args...); }

const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;
vector<int> edges[MAXN];
vector<int> invrs[MAXN];

vector<int> sameColor[MAXN];
int color[MAXN];

vector<int> order;
bool vis[MAXN];

void dfsOrder(int u) {
    vis[u] = true;
    for (int v : edges[u])
        if (!vis[v]) dfsOrder(v);
    order.push_back(u);
}

void dfsColor(int u, int curColor) {
    color[u] = curColor;
    sameColor[curColor].push_back(u);

    for (int v : invrs[u])
        if (!color[v]) dfsColor(v, curColor);
}

map<int, int> adj[MAXN];
set<int> rev[MAXN];

ll kosaraju(int n) {
    for (int i = 0; i < n; i++)
        if (!vis[i]) dfsOrder(i);
    reverse(order.begin(), order.end());

    int curColor = 0;
    for (int u : order)
        if (!color[u]) dfsColor(u, ++curColor);

    // for (int i = 1; i <= curColor; i++) {
    //  printf("%d: ", i);
    //  for (int v : sameColor[i]) {
    //      printf("%d ", v);
    //  }
    //  printf("\n");
    // }


    ll ans = 0;
    map<int, int> cnt;
    for (int c = 1; c <= curColor; c++) {
        for (int u : sameColor[c]) {
            cnt.clear();

            set<int> vx;
            for (int v : edges[u]) {
                if (color[u] == color[v]) continue;
                vx.emplace(color[v]);
                cnt[color[v]]++;
                rev[color[v]].emplace(c);
            }

            for (auto p : vx) {
                adj[c][p]++;
            }

            for (auto p : cnt) {
                ans += sameColor[p.first].size() - p.second;
            }
        }
    }

    ll cur_qtt = n;
    for (int u = 1; u <= curColor; u++) {
        cur_qtt -= sameColor[u].size();
        ll sum = cur_qtt;

        for (auto v : adj[u]) {
            if (v.first < u) continue;
            ans += ll(sameColor[u].size() - v.second) * (long long)sameColor[v.first].size();
            sum -= sameColor[v.first].size();
        }

        for (int v : rev[u]) if (v > u) sum -= sameColor[v].size();
        ans += sameColor[u].size() * sum;
    }

    return ans;
}

int main() {
    int n, m; scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v; scanf("%d%d", &u, &v);
        edges[u].push_back(v);
        invrs[v].push_back(u);
    }

    printf("%lld\n", kosaraju(n));
}