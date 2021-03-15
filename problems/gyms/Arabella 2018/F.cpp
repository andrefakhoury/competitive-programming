#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 100007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

int f[100];
int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;

    while(t--) {
        int ones = 0;
        int len = 0;
        for(int i = 0; i < 26; ++i) {
            cin >> f[i];
            if(f[i] > 1) len += 2;
            ones += f[i] == 1;
        }

        
        if(ones) len++;
        if(len == 0) {
            cout << 0 << ' ' << 0 << '\n';
            continue;
        }
        int tot = 0x3f3f3f3f;

        for(int i = 0; i < 26; ++i) {
            if(f[i] > 1) tot = min(tot, f[i]);
        }


        if(len%2 == 0) cout << len  << ' ' << tot/2 << '\n';
        else cout << len << ' ' << min(tot/2, ones) << '\n';


    }
}