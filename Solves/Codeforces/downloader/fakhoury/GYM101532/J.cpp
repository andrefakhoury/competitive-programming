#include <bits/stdc++.h>
using namespace std;
 #define fi first
#define se second
#define eb emplace_back
#define mk make_pair
#define pb push_back
 #define MOD 1000000007
 typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
 const int MAXN = 2e5 + 5;
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
     int t;
    cin >> t;
        for(int w=0; w<t; w++){
        int n;
        long long int m = 1;
         cin >> n;
         for(int i=0; i<n; i++){
            long long int x;
            cin >> x;
             m *= (x+1);
            m = m%MOD;
        }
         cout << (m-1 + MOD)%MOD << "\n";
    }
  return 0;
}