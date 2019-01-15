#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 300015, INF = 0x3f3f3f3f;

int n, m;
vector<string> t;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;

	t.resize(n+1);

	for (int i = 1; i <= n; i++) {
		string x; cin >> x;
		t[i] = "0" + x;
	}

}
