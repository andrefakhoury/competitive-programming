#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long
#define endl "\n";
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    int cont =0;
    while(t--)
    {
        cont ++ ;
        ll int n,d,c;
        ll int resp=0;
        cin >> n >> d >> c;
        resp = n*d;
        vector<ll int>v;
        for(int i=0;i<n;i++)
        {
           ll int a;
           cin >> a;
           a*=1LL; 
           v.pb(a);
        }
        sort(v.begin(),v.end());
        for(ll int i=0;i<v.size();i++)
        {
            ll int passou = i+1LL;
            resp = min(resp,passou*v[i]*c + (n-passou)*d);
        }
        cout << "Case " << cont <<": " << resp << endl;
    }

    return 0;
}