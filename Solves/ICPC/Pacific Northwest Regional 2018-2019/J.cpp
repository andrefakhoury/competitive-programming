#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define se second
#define fi first

typedef long long ll;
typedef pair<int, int> pii;
const int MAXN = 1e5 + 5;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, s; cin >> n >> s;
    int maxi = -1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        maxi = max(maxi, x);
    }

    int ans = (maxi * s + 999) / 1000;
    cout << ans << endl;
    return 0;
}