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

int carta(string c) {
	if (c == "A") return 1;
	if (c == "J") return 11;
	if (c == "Q") return 12;
	if (c == "K") return 13;
	return stoi(c);
}

vector<int> card;

int testar(int x) {
	int sum = 0, qt = 0, bk = 0;
	for (int i = 0; i < card.size(); i++) {
		sum += card[i]; qt++;
		if (sum > x) {
			return 0;
		} else if (sum == x) {
			sum = 0; 
			bk = max(bk, qt);
		} 
	}

	return bk;
}

int main () {
	ios::sync_with_stdio(false);
	int n, p, a, sum = 0, each; cin >> n >> p;
	string c;
	for(int i = 0; i < n; i++) {
		cin >> c;
		card.pb(carta(c));
		sum += card[i];
	}
	each = sum/p;
	int tot = testar(each);
	while(!tot) {
		each++;
		tot = testar(each);
	} 
	printf("%d %d\n", tot, each);

	return 0;
}