#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int isVogal(char c) {
	if (c == "a" || c == "e" || c == "i" || c == "o" || c == "u") {
		return 1;
	} return 0;
}

int main () {
	ios::sync_with_stdio(false); cin.tie(0);
	string s; cin >> s;
	for (int i = 0; i < (int)s.size(); i++) {
		if (!isVogal(s[i])) {
			if (s[i] != "n") {
				if (i < (int)s.size()-1) 
					if (!isVogal(s[i+1])) {
						cout << "NO\n";
						return 0;
					}
			}
		}
	} int maximo = (int)s.size() -1;
	if (!isVogal(s[maximo]) && s[maximo] != "n") { cout << "NO\n"; return 0; }
	cout << "YES\n";
	return 0;
}