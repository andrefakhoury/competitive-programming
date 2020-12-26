#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long

typedef pair<int, int> pii;


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;

    for (int  tt = 1; tt <= t; tt++) {
        int a, b, c, d;
        cin >> a >> b >>c  >>d;

        int t1 = 60*a + b;
        int t2 = 60*c + d;

        int ans = t2-t1;

        cout << "Case " << tt << ": " << ans << "\n";
    }
}