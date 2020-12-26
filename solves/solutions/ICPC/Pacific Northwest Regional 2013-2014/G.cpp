#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

unsigned long long f[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    f[0] = f[1] = 1;
    f[2] = 2;
    f[3] = 4;

    for (int i = 4; i <= 67; i++) {
        f[i] = f[i-1] + f[i-2] + f[i-3] + f[i-4];
    }

    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << f[x] << '\n';
    }
    

    return 0;
}