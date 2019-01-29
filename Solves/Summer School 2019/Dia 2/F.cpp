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
#define endl "\n"
#define MAX 500
int n;
int appoiment;
int demoraida[MAX];
int demoravolta[MAX];
std::vector<int> estacaoida[MAX],estacaovolta[MAX];
int menor=INF;
int dp[MAX][MAX];
int back(int est,int tempo)
{
	//cout << "Estou na estacao = " << est << " tempo = " << tempo << endl;
	int prox1;
	int prox2;
	
	if(tempo>appoiment)
		return INF;
	if(dp[est][tempo]!=-1)
		return dp[est][tempo];
	if(est!=n-1)
		prox1 = *(lower_bound(estacaoida[est].begin(),estacaoida[est].end(),tempo));
	else
		prox1 = INF;
	if(est!=0)
		prox2 = *(lower_bound(estacaovolta[est].begin(),estacaovolta[est].end(),tempo));
	else
		prox2 = INF;
	////cout << "Tempo de passar ida = " << prox1 << " volta = " << prox2 << endl;
	
	if(est == n-1)
	{
		//cout << "tempoF = " << tempo << endl;
	 	int resp = min(appoiment-tempo,(back(est-1,demoravolta[est]+prox2)+prox2-tempo));
	 	//cout << "Estou printando o min final = " << resp << endl;
		return dp[est][tempo] = resp;
	}
	else if(est == 0)
	{
		int val = back(est+1,demoraida[est]+prox1)+prox1-tempo;
		return dp[est][tempo] = back(est+1,demoraida[est]+prox1)+prox1-tempo;
		//return back(est+1,demoraida[est]+prox1)+prox1-tempo;
	}
	else
	{
		//return min(back(est+1,demoraida[est]+prox1)+prox1-tempo,back(est-1,demoravolta[est]+prox2)+prox2-tempo);
		return dp[est][tempo] = min(back(est+1,demoraida[est]+prox1)+prox1-tempo,back(est-1,demoravolta[est]+prox2)+prox2-tempo);
	}
}


void inicializa()
{
	menor = INF;
	for(int i=0;i<MAX;i++)
	{
		estacaoida[i].clear();
		estacaovolta[i].clear();
	}
	memset(dp,-1,sizeof dp);
}
int main()
{	
	fastcin;
	cin>>n;
	int casos=1;
	while(n!=0)
	{
		int saidaida,saidavolta;
		int tempoini[MAX],tempofim[MAX];
		inicializa();
		cin >> appoiment;
		for(int i=0;i<n-1;i++)
			cin >> demoraida[i];
		
		for(int i =1;i<n;i++)
			demoravolta[i] = demoraida[i-1];
		
		demoraida[n-1] = INF;
		demoravolta[0] = INF;
		
		cin >> saidaida;
		
		for(int i=0;i<saidaida;i++)
		{
			cin >> tempoini[i];
		}
		cin >> saidavolta;
		for (int i = 0; i < saidavolta; ++i)
		{
			cin >> tempofim[i];
		}

		int sum = 0;
		for(int i=0;i<n-1;i++)
		{
			for(int j=0;j<saidaida;j++)
			{
				estacaoida[i].pb(sum+tempoini[j]);
			}
			sum+=demoraida[i];
		}
		
		sum =0;
		for(int i =n-1;i>=1;i--)
		{
			for(int j=0;j<saidavolta;j++)
			{
				estacaovolta[i].pb(sum+tempofim[j]);
			}
			sum+=demoravolta[i];
		}
		for(int i=0;i<n;i++)
		{
			estacaoida[i].pb(INF);
			estacaovolta[i].pb(INF);
		}

		int resp=0;
		resp = back(0,0);
		if(resp<300)
		{
			cout << "Case Number " << casos << ": " << resp << endl;
		}
		else
			cout << "Case Number " << casos << ": impossible"<< endl;
		cin >> n;
		casos++;
	}

}