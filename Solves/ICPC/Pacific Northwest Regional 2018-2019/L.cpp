#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define se second
#define fi first


int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    int resp = -1;
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        int l,r;
        cin >> l >> r;
        v.pb(mp(l,r));
    }
    for(int i=0;i<=n;i++)
    {
        int cont =0;
        
        for(int j=0;j<n;j++)
        {
            int l = v[j].fi;
            int r = v[j].se; 
            if(i>=l and i<=r)
                cont++;
        }
        if(cont == i)
            resp = i;
    }
    cout << resp << endl;
    return 0;
    /*  
        
3
1 1
2 3
2 2

8
0 1
1 7
4 8
3 7
1 2
4 5
3 7
1 8
    */

}