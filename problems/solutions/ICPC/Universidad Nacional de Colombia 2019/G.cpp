#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define DEBUG false
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAX = 1e4 + 5;
bool vis[MAX];
set<int> depende[MAX];
vector<int> grafo[MAX],inv[MAX];
pair<int,int> info[MAX];
int dfs(int a)
{
	vis[a] = true;
	int aux = 0;
	for(int i=0;i<grafo[a].size();i++)
	{
		if(vis[grafo[a][i]] == false)
		{
			aux = max(aux,dfs(grafo[a][i]));
		}
		else
			aux = max(aux,info[grafo[a][i]].fi);
	}
	aux++;
	info[a].fi = aux;
	info[a].se = (int)grafo[a].size();
	return aux;

}
int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n,k;
	cin >> n >> k;
	for(int i=0;i<n;i++)
	{
		int a;
		cin >> a;
		if(a == 0)
			continue;
		a--;
		grafo[i].pb(a);
		inv[a].pb(i);
		depende[a].insert(i);
	}
	for(int i=0;i<n;i++)
	{
		if(vis[i] == false)
		{
			dfs(i);	
		}
	}
	if(DEBUG)
	{
		for(int i =0 ;i<n;i++)
			cout << "i = " << i << " nivel = " << info[i].fi << " filhos = " << info[i].se << endl;
	}
	priority_queue<tuple<int,int,int> > fila;
	for(int i=0;i<n;i++)
	{
		if(depende[i].size()== 0)
		{
			tuple <int,int,int> aux;
			aux = make_tuple(info[i].fi,info[i].se,i);
			fila.push(aux);
		}
	}
	int resp =0;
	while(fila.size())
	{
		resp++; 
		vector<tuple<int,int,int> > add;
		for(int i=0;i<k and fila.size()>0;i++)
		{
			tuple<int,int,int> at = fila.top();
			int atnum,level,quant;
			tie(level,quant,atnum) = at;
			fila.pop();
			for(int j = 0;j<grafo[atnum].size();j++)
			{
				int next = grafo[atnum][j];		
				tuple<int,int,int> nextt = make_tuple(info[next].fi,info[next].se,next);
				if(depende[next].count(atnum))
					depende[next].erase(atnum);
				if(depende[next].size() == 0)
					add.pb(nextt);
			}
		}
		for(int i=0;i<add.size();i++)
			fila.push(add[i]);
	}
	cout << resp << endl;

		
	return 0;
}