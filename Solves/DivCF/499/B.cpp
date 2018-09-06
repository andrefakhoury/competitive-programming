#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f

#define MAXN 200

typedef long long ll;
typedef pair<int, int> pii;

map<int, int> food;
int n, m, x;
vector<int> fd;

int tenta(int qtd) {
	int pessoa = 0;
	for (int i = 0; i < (int)fd.size(); i++) {
		if (fd[i] >= qtd)
			pessoa += (int)fd[i]/qtd;
	}

	if (pessoa >= n) return 1;
	return 0;
}

int main () {
	ios::sync_with_stdio(0); cin.tie(NULL);
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> x;
		food[x]++;
	}

	for (auto it = food.begin(); it != food.end(); it++) {
		fd.pb(it->second);
	}

	int maxi = 0;
	for (int i = 1; i <= 100; i++) {
		if (tenta(i)) maxi = i;
	}
	cout << maxi << endl;
	

	return 0;
}