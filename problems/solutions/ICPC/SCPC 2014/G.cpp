#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("O3")
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long

typedef pair<int, int> pii;
const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

const int n = 5, m = 6;
bool vis[5][6];

map<vector<string>, bool> st;

bool valid(int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < m;
}

void ffrec(vector<string>& s, int i, int j, char ori) {
    if (!valid(i, j)) return;
    if (s[i][j] != ori) return;
    s[i][j] = 'X';
    if (vis[i][j]) return;
    vis[i][j] = true;

    ffrec(s, i+1, j, ori);
    ffrec(s, i-1, j, ori);
    ffrec(s, i, j+1, ori);
    ffrec(s, i, j-1, ori);
}

vector<string> ff(vector<string>& s, int i, int j) {
    memset(vis, 0, sizeof vis);

    vector<string> ret(n);
    for (int i = 0; i < n; i++) ret[i] = s[i];

    ffrec(ret, i, j, s[i][j]);
    return ret;
}

int moreThanOne(vector<string>& s, int i, int j) {
    int cnt = 0;

    cnt += valid(i+1, j) && (s[i+1][j] == s[i][j]);
    cnt += valid(i-1, j) && (s[i-1][j] == s[i][j]);
    cnt += valid(i, j+1) && (s[i][j+1] == s[i][j]);
    cnt += valid(i, j-1) && (s[i][j-1] == s[i][j]);

    return cnt;
}

void fallDown(vector<string>& s) {
    for (int j = 0; j < m; j++) {
        int l = n-1;
        for (int i = n-1; i >= 0; i--) {
            if (s[i][j] != 'X') {
                if (i != l) swap(s[i][j], s[l][j]);
                l--;
            }
        }
    }
}

bool entireColumn(vector<string>& s, int j) {
    for (int i = 0; i < n; i++) if (s[i][j] != 'X') return false;
    return true;
}

void moveLeft(vector<string>& s) {
    int l = 0;
    for (int j = 0; j < m; j++) {
        if (!entireColumn(s, j)) {
            if (l != j) for (int i = 0; i < n; i++) swap(s[i][l], s[i][j]);
            l++;
        }
    }
}

bool won(vector<string>& s) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != 'X') return false;
        }
    }

    return true;
}

int getQtt(vector<string>& s, int i, int j, char ori, vector<vector<bool> >& used) {
    if (!valid(i, j)) return 0;
    if (s[i][j] != ori) return 0;
    if (used[i][j]) return 0;
    used[i][j] = true;

    int ret = 1;
    ret += getQtt(s, i+1, j, ori, used);
    ret += getQtt(s, i-1, j, ori, used);
    ret += getQtt(s, i, j-1, ori, used);
    ret += getQtt(s, i, j+1, ori, used);

    return ret;
}

bool solve(vector<string> s) {
    if (st.count(s)) return st[s];
    if (won(s)) return st[s] = true;

    vector<pair<int, pair<int, int> > > all;
    vector<vector<bool> > used(n, vector<bool>(m));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'X') continue;

            int c = getQtt(s, i, j, s[i][j], used);
            if (c > 1) all.push_back(mp(c, mp(i, j)));
        }
    }

    sort(all.rbegin(), all.rend());
    for (auto xx : all) {

        int i = xx.se.fi, j = xx.se.se;
        
        vector<string> cur = ff(s, i, j);
        fallDown(cur); moveLeft(cur);
        if (solve(cur)) return st[s] = true;
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         if (s[i][j] != 'X' && moreThanOne(s, i, j)) {
    //             // cout << "OI" << endl;
    //             
    //         }
    //     }
    // }

    return st[s] = false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t; cin >> t;

    for (int cs = 1; cs <= t; cs++) {
        vector<string> s = vector<string>(n);
        for (string& x : s) cin >> x;

        cout << "Case " << cs << ": " << (solve(s) ? "Yes" : "No") << "\n";
    }

    return 0;
}