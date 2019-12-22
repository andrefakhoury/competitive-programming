#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;
const int INF = 0x3f3f3f3f;
const double pi = acos(-1);

vector<double> pies;
int n, f;

double volume(int r) {
	return pi * r * r;
}

int comer(double volume) {
	int comeu = 0;
	for(int i = 0; i < pies.size(); i++) {
		if(pies[i] < volume) continue;
		comeu += floor(pies[i]/volume);
	}

	if(comeu < f) return 0;
	else return 1;

}

int main() {
	// ios::sync_with_stdio(false); cin.tie(NULL);

	int t; cin >> t;

	while(t--) {
		
		cin >> n >> f;
		f++;

		double low = 0;
		double high = 10000000000000.0;

		for(int i = 0; i < n; i++) {
			int r; cin >> r;
			double v = volume(r);
			pies.push_back(v);
		}

		sort(pies.rbegin(), pies.rend());
		
		int cont = 1000;
		while(cont--) {
			//cout << high << " " << low << endl;
			double mid = (high + low)/2.0;
			int retorno = comer(mid);
			if(!retorno) high = mid;
			else low = mid;
		}

		cout << fixed << setprecision(4) << low<< endl;
		pies.clear();

	}

	return 0;
}