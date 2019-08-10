#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define lim 4294967295ll




int main()
{	
	fastcin;
	ll int x=0;
	int n;
	cin >> n;
	stack<ll int > st;
	st.push(0LL);
	while(n--)
	{
		string s;
		cin >> s;
		if(s == "for")
		{
			ll int quant;
			cin >> quant;
			ll int pilha = 0;
			if(st.top() == -1)
			{
				st.push(-1);
				continue;
			}
			if(st.top() == 0)
				pilha = quant;
			else
				pilha = (ll int )st.top()*quant;
			if(pilha>lim)
			{
				pilha = -1;
			}
			st.push(pilha);
		}
		else if(s == "end")
			st.pop();
		else
		{
			if(st.top() == -1)
			{
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
			x+=(ll int)st.top();
			if(st.top() == 0)
				x++;
			if(x>lim)
			{
				cout << "OVERFLOW!!!" << endl;
				return 0;
			}
		}
	}
	cout << x << endl;
	return 0;
}