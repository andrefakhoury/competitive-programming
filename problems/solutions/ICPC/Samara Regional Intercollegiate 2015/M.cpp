#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mk make_pair

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, q; cin >> n >> q;

    for(int i = 0; i < q; ++i) {
        int l, k; cin >> l >> k;

        if(n < l) cout << 0 << '\n';
        else cout << 2 * ((n - l) / (l + k)) + 1 + ((n - l)%(l + k) >= k) << ' '; 
    }
    cout << endl;
}