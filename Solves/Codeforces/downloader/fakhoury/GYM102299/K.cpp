#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
 typedef long long ll;
 const int maxn = 505050;
 ll v[maxn];
 int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
     int n;
    cin >> n;
     for (int i = 0; i < n; i++) cin >> v[i];
     sort(v, v+n);
     ll at = 0;
     for (int i = 0; i < n; i++) {
        if (at+1 < v[i]) break;
        at += v[i];
    }
     cout << at+1 << "\n";
     return 0;
}