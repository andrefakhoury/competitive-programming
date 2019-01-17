#include<bits/stdc++.h>

#define DEBUG 0
#define MAX 100005
#define INF 0x3f3f3f3f
#define mset(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define watch(x) cout << (#x) << "is" << (x) << endl


using namespace std;

int gp[3];

int main(int argc, const char *argv[]){

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int ans = 0;
	int n; cin >> n;

	for(int i = 0; i < n; i++){
		int aux;
		cin >> aux;
		gp[aux]++;
	}

	if(gp[1] > gp[2]){
		ans = gp[2];
		gp[1] -= gp[2];
		
		while(gp[1] >= 3){
			gp[1] -= 3;
			ans++;
		}

	} else
		ans = gp[1];

	cout << ans << endl;

	return 0;
}