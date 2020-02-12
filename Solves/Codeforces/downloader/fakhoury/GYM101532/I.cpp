#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back
 typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 const int MAXN = 2e5 + 5;
 int last[200010];
int jump[200010];
int cor[200010];
int dp[200010];
int n;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
     int t;
    cin >> t;
     for(int w=0; w<t; w++){
        cin >> n;
         memset(last, -1, sizeof(last));
        memset(jump, -1, sizeof(jump));
        memset(dp, 0x7f, sizeof(dp));
         for(int i=0; i<n; i++){
            cin >> cor[i];
             if(last[cor[i]] != -1) jump[last[cor[i]]] = i;
             last[cor[i]] = i;
        }
         dp[0] = 0;
        for(int i=0; i<n-1; i++){
            if(dp[i] + 1 < dp[i+1]){
                dp[i+1] = dp[i] + 1;
            }
             if(jump[i] != -1 && dp[i] + 1 < dp[jump[i]]){
                dp[jump[i]] = dp[i] + 1;
            }
        }
         cout << dp[n-1] << "\n";
    }
  return 0;
}