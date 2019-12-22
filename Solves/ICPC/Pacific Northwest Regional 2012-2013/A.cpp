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
	int t;
	cin >> t;
	int cont =0;
	while(t--)
	{
		cont ++ ;
		ll int resp = 0;
		for(ll int i=1;i<=6;i++)
		{
			ll int a;
			cin >> a;
			if(i<=3)
				resp+= i*a;
			else if(i!=6)
				resp+=(i-1)*a;
			else
				resp+=10*a;			
		}
		for(ll int i=1;i<=7;i++)
		{
			ll int a;
			cin >> a;
			if(i<=2)
				resp-= i*a;
			else if(i == 3 or i == 4)
				resp-=2LL*a;
			else if(i == 5)
				resp-= 3LL*a;
			else if(i == 6)
				resp-=5LL*a; 
			else
				resp-=10LL*a;
		}
		if(resp<0)
		{
			cout << "Battle " << cont << ": Evil eradicates all trace of Good" << endl;
		}
		else if(resp ==0)
			cout << "Battle " << cont << ": No victor on this battle field" << endl;
		else
			cout << "Battle " << cont << ": Good triumphs over Evil" << endl;
	}
    return 0;
}