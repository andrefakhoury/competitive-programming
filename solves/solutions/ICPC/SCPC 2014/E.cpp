#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long
#define endl "\n"

typedef pair<int, int> pii;
int k;
int dp[1003];
const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;
int solve(int at)
{
    bool possivel[1003];
    memset(possivel,0,sizeof possivel);
    if(at < k)
        return 0;
    if(dp[at]!=-1)
        return dp[at];
    for(int i =1;i<=at;i++)
    {
        if(at - (i-1) - k < 0)
            break;
        int esq = solve(i-1);
        int dir = solve(at - (i-1) -k);
        possivel[esq^dir] = true;
    }
    int resp =0 ;
    int aux = 0;
    while(possivel[aux])
        aux++;
    return dp[at] = aux;
        
}
int main() 
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    int cont =0;
    while(t--)
    {
        memset(dp,-1,sizeof dp);
        cont ++;
        cout << "Case " << cont << ": ";
        int n;
        cin >> n >> k;
        if(solve(n))
            cout << "Winning" << endl;
        else
            cout << "Losing" << endl;
    }
    return 0;
}