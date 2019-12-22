#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mk make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;
const int INF = 0x3f3f3f3f;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	string s; cin >> s;n--;
	bool ans = s[0] == 'T';
	while(n--) {
		string x; cin >> x;
		if (x[0] == 'L') ans = !ans;
	}

	cout << (ans ? "TRUTH" : "LIE") << endl;
	

	return 0;
}