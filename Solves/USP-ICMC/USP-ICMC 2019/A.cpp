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
const int BLOCK = 316;
 
int a[MAXN], maxi[MAXN], ans[MAXN];
 
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    memset(ans, -1, sizeof ans);
 
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
 
    for (int i = 1; i <= n; i++) maxi[i/BLOCK] = max(maxi[i/BLOCK], a[i]);
 
    for (int i = 1; i <= n; i++) {
        if (i == n) {
            ans[i] = 0;
            continue;
        }
 
        // cout << i << ": ";
        int l = i, r = min(i + a[i], n);
        
        int lo = l / BLOCK, hi = r / BLOCK;
 
        for (int j = i + 1; j <= r && j/BLOCK == lo; j++) {
            if (a[j] > a[i]) {
                ans[i] = j - i - 1;
                break;
            }
        }
 
        if (~ans[i]) continue;
 
        int last = -1;
        for (int j = lo + 1; j < hi; j++) {
            if (maxi[j] > a[i]) {
                // cout << "2" << endl;
                last = j;
                break;
            }
        }
 
        if (last != -1) hi = last;
 
        for (int j = max(hi * BLOCK, l); j <= r; j++) {
            if (a[j] > a[i]) {
                // cout << a[i] << " vs " << a[j] << endl;
                ans[i] = j - i - 1;
                break;
            }
        }
 
        if (~ans[i]) continue;
        else ans[i] = r - i;
 
        
    }
 
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    } cout << endl;
 
    
 
    return 0;
}