#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main () {
	ios::sync_with_stdio(false);

	string a, b; cin >> a >> b;
	int cont = 0;

	if (a.size() < b.size()) {
		string aux = b;
		b = a;
		a = aux;
	}

	//a eh o maior
	int i, j;
	for (i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; i--, j--) {
		if (a[i] != b[j]) {
			cout << i+j+2 << endl;
			return 0;
		}
	}
	if (i != j) {
		cout << i+j+2 << endl;
	} else
		cout << 0 << endl;
	return 0;


}