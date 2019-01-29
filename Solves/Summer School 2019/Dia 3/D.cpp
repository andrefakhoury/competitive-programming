#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b)	 for(int (i)=(a);(i) < (b); ++(i))
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);
#define ll long long
#define endl "\n"
#define MAX 200



int main()
{	
	fastcin;
	int t;
	
		int n,d,tempo,m;
		cin >> n >> d >> tempo >> m;
		int cost[MAX];
		vector<pair <int,int > > grafo[MAX];
		memset(cost,INF,sizeof cost);
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			cin >> a >> b >> c;
			grafo[b].pb(mp(c,a));
		}
		cost[d] = 0;
		priority_queue<pair <int,int > >pq;
		pq.push(mp(0,d));
		while(pq.size()!=0)
		{
			int custoat = -pq.top().fi;
			int at = pq.top().se;
			pq.pop();
			for(int i=0;i<grafo[at].size();i++)
			{
				if(cost[grafo[at][i].se] > cost[at] + grafo[at][i].fi)
				{
					cost[grafo[at][i].se] = cost[at]+grafo[at][i].fi;
					pq.push(mp(-cost[grafo[at][i].se],grafo[at][i].se));

				}
			}
		}
		int resp =0;
		for(int i=1;i<=n;i++)
		{
			if(cost[i]<=tempo)
				resp++;
		}
		cout << resp << endl;
		t--;
	
	
}
