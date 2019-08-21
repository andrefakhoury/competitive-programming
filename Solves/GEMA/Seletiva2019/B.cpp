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
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
 
    ll a, b; cin >> a >> b;
 
    set<ll> ans;
 
    for (ll i = 1; i * i <= a; i++) {
        if (a%i == 0) {
            if (i % b == 0) ans.insert(i);
            if (a/i % b == 0) ans.insert(a/i);
        }
    }
 
    for (ll i : ans) cout << i << ' ';
    cout << endl;    
 
    return 0;
}