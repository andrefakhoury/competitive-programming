#include <bits/stdc++.h>
using namespace std;
 #define ll long long
#define pb push_back
#define endl '\n'
#define fcin ios::sync_with_stdio(false); cin.tie(nullptr);
#define inf 0x3f3f3f3f
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 /* 
* stuff you should look for
* ll overflow, array bounds
* special cases (n=1?), set tle
*/
 const ll N = 1000000007LL;
ll a[(int)2e5+5];
 ll isprime(ll k){
 ll n = 0;
 for(ll j = 2; j*j <= k+1; j++){
  if(k%j==0 and k!=j) n++;
 }
 return n == 0 and k != 1;
}
 int main(){
    fcin;
  ll n;
 cin >> n;
 for(ll i = 0; i < n; i++) cin >> a[i];
  sort(a, a+n);
  ll y;
 if(n&1){
  ll x = a[n/2];
  y = x;
 } else {
  ll x = a[n/2];
  y = a[(n-1)/2];
  y = (x+y)/2;
 }
  ll l = 2LL, r = 1000000007LL;
 for(ll i = y; i >= 2; i--){
  if(isprime(i)){
   l = i;
   break;
  }
 }
 for(ll i = y; i <= N; i++){
  if(isprime(i)){
   r = i;
   break;
  }
 }
 ll ans3 = 0, ans4 = 0;
 if(!isprime(l)) l = r;
 if(!isprime(r)) r = l;
 for(ll i = 0; i < n; i++) ans3+=abs(a[i] - l);
 for(ll i = 0; i < n; i++) ans4+=abs(a[i] - r);
  cout << min({ans3, ans4});
    return 0;
}