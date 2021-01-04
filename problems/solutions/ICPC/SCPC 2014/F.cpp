#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int tt;
    cin >> tt;

    for (int t = 1; t <= tt; t++) {
        ll n, m;
        cin >> n >> m;


        ll l = 0, r = n;

        while (r-l > 1) {
            ll mid = (l+r)/2;

            ll sum = (mid+1)*(mid)/2;

            if (sum <= m-1) l = mid;
            else r = mid;
        }

        ll top = l;
        ll bot = m - (top+1)*(top)/2 - 1;

        cout << "Case " << t << ": " << top << " " << bot << "\n";
    }

    return 0;
}