#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 500005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string getPattern(string& x) {
	string pat;
	for (int i = 0; i < x.size(); i++) {
		if ((x[i] - '0')%2 == 0) pat.pb('0');
		else pat.pb('1'); 
	}

	string bb;
	for (int i = 0; i < 20 - pat.size(); i++) bb.pb('0');
	bb = bb + pat;

	return bb;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int q; cin >> q;

	map<string, int> freq;
	while(q--) {
		char op; cin >> op;
		if (op == '+') {
			string x; cin >> x;
			freq[getPattern(x)]++;
		} else if (op == '-') {
			string x; cin >> x;
			freq[getPattern(x)]--;
		} else {
			string s; cin >> s;

			string x;
			for (int i = 0; i < 20 - s.size(); i++) x.pb('0');
			x = x + s;
			cout << freq[x] << "\n";
		}
	}
	return 0;
}