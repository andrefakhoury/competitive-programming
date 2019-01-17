#include<bits/stdc++.h>

#define DEBUG 0
#define MAX 100005
#define INF 0x3f3f3f3f
#define mset(x,y) memset(x, y, sizeof(x))
#define pb push_back
#define watch(x) cout << (#x) << "is" << (x) << endl

typedef long long ll;

using namespace std;

vector <int> a;
int suma, sumb;

int main(int argc, const char *argv[]){

	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n; cin >> n;

	for(int i = n; i >= 1; i--){
		if(suma <= sumb){
			a.pb(i);
			suma+=i;
		}
		else{
			sumb+=i;	
		}
	}

	cout << abs(sumb-suma) << endl;
	cout << (int)a.size() << " ";
	for(int i = 0; i < (int)a.size(); i++){
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}