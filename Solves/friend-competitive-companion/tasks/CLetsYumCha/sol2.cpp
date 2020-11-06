#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,x,t,k,budget;
double V[105], W[105];
double DP[105][1200][25];

double solve(int u, int w, int numelement){
    //printf("%d %.2lf %d\n",u,w*1.1,numelement);
    if(w > budget || numelement > 2*(n+1)) return -INF;
    double &value = DP[u][w][numelement];
    if(value != -1) return value;
    if(u == k || numelement == 2*(n+1)) return 0.0;
    value = max(solve(u+1,w,numelement), solve(u+1,w+W[u],numelement+1) + V[u]);
    value = max(value, solve(u+1,w+W[u]*2, numelement+2) + V[u]*2);
    return value;
}

int main(){
    ios::sync_with_stdio(false);
    while(cin >> n >> x >> t >> k && n + x + t + k != 0){
        budget = floor(double(x * (n + 1)) / 1.1 + 1e-6);
        for(int i = 0; i < k; i++){
            cin >> W[i];
            int sum = 0, total = 0;
            for(int j = 0; j <= n; j++)
                cin >> sum, total+=sum;
            V[i] = (double)total/(n+1);
        }
        //memset(DP,0,sizeof DP);
        for(int i = 0; i <= 103; i++) for(int j = 0; j <= 1150; j++) for(int k = 0; k <= 25; k++) DP[i][j][k] = -1;
        double ans = solve(0,t*(n+1),0);
        printf("%.2lf\n", (ans < 0) ? 0.0 : ans );
    }
}
