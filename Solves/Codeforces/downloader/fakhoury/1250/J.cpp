#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef pair<int, int> pii;
typedef long long ll;
 const int MAXN = 30004;
 ll c[MAXN],v[MAXN];;
ll n,k; 
bool query(ll val)
{
 for(int i=0;i<n;i++)
  v[i] = c[i];
 ll foi = 0; 
 for(int i=0;i<n;i++)
 {
  ll at = v[i]/val; 
  if(at == 0 and i!=0)
   v[i]-=v[i-1];
  foi+=at;
  v[i]%=val;
  if(i!=n-1)
   v[i+1]+=v[i];
  if(foi>=k)
   return true;
 }
 return false;
}
 int main() 
{
 ios::sync_with_stdio(false); cin.tie(NULL);
 int t;
 cin >> t;
 while(t--)
 {
  cin >> n >> k;
  for(int i=0;i<n;i++)
  {
   cin >> c[i];  
  }
  ll l = 0,r = 3e17;
  while(l<r)
  {
   ll mid = (l+r+1)/2;
//   cout << "l = " << l << " r = " << r << " mid = " << mid << endl;
   if(query(mid))
    l = mid;
   else
    r = mid-1;
  }
  cout << l*k << endl;
 }
 return 0;
}