#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define ll long long
 typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;
 int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    ll int n;
    while((cin >> n))
    {
        set<int> s;
        ll int at = (ll int)n;
        ll int cont =0;
        while(s.size()!=10)
        {
            cont++;
            ll int aux = cont*at;
            while(aux>=1)
            {
                s.insert(aux%10LL);
                aux/=10LL; 
            }
        }
        cout << cont << endl;
    }
    return 0;
}