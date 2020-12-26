#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define ll long long  
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;
vector<ll int > v;
int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		v.clear();
		int n;
		cin >> n;
		for(int i=0;i<n;i++)
		{
			ll int a;
			cin >> a;
			a*=4LL;
			v.pb(a);
		} 
		sort(v.begin(),v.end());
		ll int corte = v[0] + v[n-1];
		corte/=2;
		ll int resp = -INF;
		ll int b1,b2;
		ll int p0,p1;
		for(int i=0;i<n;i++)
		{
			if(v[i] > corte)
			{
				p0 = v[i];
				break;
			}
			p1 = v[i];
		}
		b1 = p1 + v[0];
		b1/=2;
		b2 = p0 + v[n-1];
		b2/=2;
		
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{	
				ll int at = min(llabs(v[i]-v[j]),llabs(v[i] - b1) + llabs(v[j] - b2));					
				resp = max(resp,at);
			}
		}
		cout << (resp+3)/4 << "\n";
	}

	return 0;
}