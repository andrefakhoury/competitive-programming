#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 2000 + 5;
const ll  INF = 100000000000000000;

ll dp[MAXN][21];
ll acum[MAXN];
int n,d;
ll v[MAXN];
ll arredonda( ll at)
{
	ll resto = at%10;
	if(resto>=5)
	{
		resto = 10-resto;
		return at + resto;	
	}
	else 
		return at - resto;
}
ll solve(int posi,int quant)
{
	if(posi >n)	
		return 0;
	if(dp[posi][quant]!=-1)
		return dp[posi][quant];
	ll op1,op2;
	op1 = op2 = INF;
	if(quant < d)
	{
		
		for(int i = posi;i<=n;i++)
		{
			op1 = min(op1,solve(i+1,quant+1) + arredonda(acum[i] - acum[posi-1]));
		}
	}
	else
		op2 =  arredonda(acum[n] - acum[posi-1]);
	return dp[posi][quant] = min(op1,op2);
}
int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> d;
	memset(dp,-1,sizeof dp);
	acum[0] = 0;
	for(int i=1;i<=n;i++)
	{
		cin >> v[i];
		acum[i] = acum[i-1] + v[i];
	}
	cout << solve(1,0) << endl;
	return 0;
}