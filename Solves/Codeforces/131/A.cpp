#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(0); cin.tie(NULL);
#define PI acos(-1.0)
#define inf 0x3f3f3f3f3f

#define MAXN 100000
#define MAXM 100000

typedef long long ll;
typedef pair<int, int> pii;

int main () {
	ios::sync_with_stdio(0); cin.tie(NULL);
	string s; cin >> s;
	int first, all = 0; //1: minusculo; 0: maisculo
	if (s[0] < 97) first = 0;
	else first = 1;

	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] < 97) all++;
	}

	if (all == (int)s.size() || (first && all == (int)s.size()-1)) {
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] < 97) s[i] += 32;
			else s[i] -= 32;
		}
	} 
	cout << s << endl;

	return 0;
}