#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int solve[MAXN];
vector<pii> fat[MAXN];

int f(int i, int e, int d) {//i = fator primo atual, e = expoente atual, n = numero sendo montado
	if(i == fat[i].second) cout << d << endl;
	f(i+1, 1, d);
	if(e < fat[i].second) f(i , e+1, d*fat[i].first);
}

int main(int argc, char const *argv[]){
	
	for (int i = 1; i <= n; i++){
			for(int j = i; j <= n; j+=i){
				solve[j]=i;
			}
		}

	for(int i = 2; i*i<= n; i++){
		int cont = 0;
		while(n%i==0){
			cont++;
			n/=i;
		}
		if(int){
			fat[i].push_back({i, cont});
		}
	}	

	f(0, 0, 1);

	return 0;
}