#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e4 + 5;
const int INF = 0x3f3f3f3f;
vector<int> grafo[MAXN];
pair<int,int> freq[MAXN];
int pai[MAXN];
bool vis[MAXN];
int cont = 2;
int inv = 1000000000 -1;
void dfs(int a)
{
	vis[a] = true;
	freq[a].se = cont;
	cont++;
	for(int i=0;i<grafo[a].size();i++)
	{
		pai[grafo[a][i]] = a;
		if(vis[grafo[a][i]] == false)
		{
			freq[grafo[a][i]].fi = freq[a].se;
			dfs(grafo[a][i]);
		}
	}
	if(false)
		cout << "a = " << a << " freq = " << freq[a].fi << " " << freq[a].se << endl;
			
}
int main() 
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	n--;
	for(int i=0;i<MAXN;i++)
	{
		freq[i] = mp(-1,-1);
		pai[i] = -1;
	}
	for(int i=0;i<n;i++)
	{
		int a,b;
		cin >> a >> b;
		a--;
		b--;
		grafo[a].pb(b);
		grafo[b].pb(a);
	}
	if(n == 1)
	{
		cout << "1 2" << endl << "1 2" << endl;
		return 0;
	}
	int root;
	for(int i=0;i<n;i++)
		if(grafo[i].size() == 1)
			root = i;
	freq[root].fi = 1;
	dfs(root);	
	for(int i=0;i<=n;i++)
	{
		cout << freq[i].fi << " " << freq[i].se;
		cout << endl;
	}
	return 0;
}