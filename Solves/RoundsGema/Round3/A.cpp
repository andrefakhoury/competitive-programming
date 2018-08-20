#include <bits/stdc++.h>
#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair

#define inf 0x3f3f3f3f
#define MAXN 100000
#define MAXM 100000

//ios::sync_with_stdio(false);

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


int main () {
	ios::sync_with_stdio(false);
	
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	for (int i = 0; i < n; i++) {
		s[i] =  (s[i]-'a'+k)%26 + 'a';
	}
	cout << s << endl;
	

	return 0;
}