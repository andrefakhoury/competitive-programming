#include <bits/stdc++.h>
using namespace std;

char mapa[60][60];
bool vis[60][60];
int n, m;

void flood(int i, int j, char c) {
    if (i > n || i <= 0 || j > m || j <= 0) return;
    if (mapa[i][j] != c) return;
    if (vis[i][j]) return;

    vis[i][j] = true;
    flood(i+1, j, c);
    flood(i-1, j, c);
    flood(i, j+1, c);
    flood(i, j-1, c);
}

bool cmp(pair<int, char>& a, pair<int, char>& b) {
    if (a.first == b.first) {
        return a.second < b.second;
    } else {
        return a.first > b.first;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        memset(vis, 0, sizeof vis);

        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) cin >> mapa[i][j];
        }

        map<char, int> ans;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (!vis[i][j]) {
                    ans[mapa[i][j]]++;
                    flood(i, j, mapa[i][j]);
                }
            }
        }

        vector<pair<int, char> > all;
        for (char c = 'a'; c <= 'z'; c++) {
            if (ans[c]) all.emplace_back(ans[c], c);
        }

        cout << "Galaxia #" << cs << '\n';
        sort(all.begin(), all.end(), cmp);
        for (int i = 0; i < (int)all.size(); i++) {
            cout << all[i].second << ": " << all[i].first << '\n';
        }

    }
    

}