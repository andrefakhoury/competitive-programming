#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 0
#define INF 100000000000000000LL
#define ll long long
typedef pair<int, int> pii;
  int main() 
{
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<ll int,ll int> > v;
   for(int i=0;i<n;i++) 
   {
       ll int p,f;
       cin >> p >> f;
       v.pb(mp(f,p));
   }
   sort(v.begin(),v.end());
   ll int sum=0, maior = -INF;
   for(int i=0;i<n;i++)
   {
       if(DEBUG)
       {
            cout << "soma = " << sum << endl;
            cout << "v[i].fi = " << v[i].fi << " se = " << v[i].se << endl;
       }
       sum+=v[i].se;
       sum-=v[i].fi;
       maior = max(sum,maior);
       sum+=v[i].fi;
   }
   cout << maior << endl;
     return 0;
}