#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int vis[N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    for(int i = 0; i < n; ++i) {
        string s; cin >> s;

        if(s[0] == '-') continue;
        if(s.size() > 7) continue;
        int x;
        sscanf(s.c_str(), "%d", &x);
        if(x >= N) continue;
        vis[x] = 1;
    }

    for(int i = 0; i < N; ++i) {
        if(vis[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }
}