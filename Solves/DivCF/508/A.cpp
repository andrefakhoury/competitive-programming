#include <bits/stdc++.h>
using namespace std;

#define DEBGG(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
#define fastcin ios::sync_with_stdio(false);
#define SZOF(v) ((int)v.size())
#define xx first
#define yy second

const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);
#define MAXN 100005

typedef long long ll;
typedef pair<int, int> pii;

int n, k;
string s;
map<char, int> m;

int main() {
	ios::sync_with_stdio(false);
	cin >> n >> k >> s;
	for (int i = 0; i < SZOF(s); i++) m[s[i]]++;

	int minimo = INF;
	for (int i = 0; i < k; i++) {
		if (m[i+'A'] == 0) {
			cout << 0 << endl;
			return 0;
		}

		minimo = min(m[i+'A'], minimo);
	}

	cout << minimo*k << endl;
	return 0;

}