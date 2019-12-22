#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

vector<string> a;
vector<vector<bool> > vis;

struct PT {
    int x, y;

    void change(int i, int j) {
        x = i, y = j;
    }
};

PT p1, p2;
int n, m;

bool valid(int i, int j) {
    return i >= 0 && j >= 0 &&
           i < n && j < m;
}

void imp() {
    cout << "NO\n";
    exit(0);
}

bool dfs1(int i, int j) {
    if (!valid(i, j)) return false;
    if (vis[i][j]) return false;
    if (a[i][j] == '#') return false;
    if (a[i][j] == '2') return true;

    vis[i][j] = true;

    if (dfs1(i+1, j)) return true;
    if (dfs1(i-1, j)) return true;
    if (dfs1(i, j+1)) return true;
    if (dfs1(i, j-1)) return true;

    return false;
}

bool dfs2(int i, int j) {
    vis[i][j] = true;

    int qtt = 0;

    qtt += valid(i+1, j) && a[i+1][j] != '#';
    qtt += valid(i-1, j) && a[i-1][j] != '#';
    qtt += valid(i, j+1) && a[i][j+1] != '#';
    qtt += valid(i, j-1) && a[i][j-1] != '#';

    if (qtt >= 3) return true;

    if (valid(i+1, j) && a[i+1][j] != '#' && !vis[i+1][j] && dfs2(i+1, j)) return true;
    if (valid(i-1, j) && a[i-1][j] != '#' && !vis[i-1][j] && dfs2(i-1, j)) return true;
    if (valid(i, j+1) && a[i][j+1] != '#' && !vis[i][j+1] && dfs2(i, j+1)) return true;
    if (valid(i, j-1) && a[i][j-1] != '#' && !vis[i][j-1] && dfs2(i, j-1)) return true;

    return false;    
}

int dfs3(int i, int j) {

    if (a[i][j] == '2') return 1;
    vis[i][j] = true;

    int ret = 0;

    if (valid(i+1, j) && !vis[i+1][j] && a[i+1][j] != '#') ret += dfs3(i+1, j);
    if (valid(i-1, j) && !vis[i-1][j] && a[i-1][j] != '#') ret += dfs3(i-1, j);
    if (valid(i, j+1) && !vis[i][j+1] && a[i][j+1] != '#') ret += dfs3(i, j+1);
    if (valid(i, j-1) && !vis[i][j-1] && a[i][j-1] != '#') ret += dfs3(i, j-1);

    return ret;
}

int main(){
    fastcin;

    cin >> n >> m;

    a.resize(n);
    vis.resize(n);
    for (vector<bool> &v : vis) v.resize(m);
    for (string& s : a) cin >> s;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') p1.change(i, j);
            if (a[i][j] == '2') p2.change(i, j);
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;

    if (!dfs1(p1.x, p1.y)) imp();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            vis[i][j] = false;

    if (!dfs2(p1.x, p1.y)) {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                vis[i][j] = false;

        if (dfs3(p1.x, p1.y) <= 1)
            imp();
    }
    
    cout << "YES\n";

    return 0;
}