#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG false
#define ll long long
typedef pair<int, int> pii;
 
const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int a[MAXN], n;
ll sum[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];

    if (sum[n]%3) return cout << "0" << endl, 0;
    ll k = sum[n] / 3;

    map<ll, int> mp;
    for (int i = 1; i <= n; i++) mp[sum[i]]++;

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += mp[sum[i] + k] && mp[sum[i] + 2 * k];

    cout << ans << endl;
    return 0;
}