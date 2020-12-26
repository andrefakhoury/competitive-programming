#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define se second
#define fi first
#define ll long long 
#define MAX 1003
#define MOD 998244353

ll int dp[MAX][MAX];
vector<int> v;
ll int back(int posi,int k)
{
    if( k ==0)
        return 1;
    if(posi == v.size())
        return 0;
    if(dp[posi][k]!=-1)
        return dp[posi][k];
    ll int op1 = back(posi+1,k)%MOD;
    ll int op2 = (back(posi+1,k-1)%MOD)*(v[posi]%MOD);
    return dp[posi][k] = (op1%MOD + op2%MOD)%MOD;
}

int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n,k;
    map<int,int>m;
    cin >> n >> k;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            dp[i][j] = -1; 
    
    for(int i=0;i<n;i++)
    {
        int a;
        cin >> a;
        m[a]++;
    }
    for(auto e:m)
        v.pb(e.se);
    
    cout << back(0,k) << endl;
    return 0;
}