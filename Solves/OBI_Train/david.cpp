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
	string s; int qt = 0;
	while(cin >> s) {
		if (qt) cout << " ";
		if (s.size() >= 4) {
			if (s[0] == s[2] && s[1] == s[3]) {
				s.erase(s.begin());
				s.erase(s.begin());
			}
		}
		cout << s; qt++;
	}

	cout << "\n";
	return 0;
}