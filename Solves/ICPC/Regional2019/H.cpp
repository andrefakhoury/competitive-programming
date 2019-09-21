#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int v, n;
	cin >> v >> n;

	int x = v*n;

	for (int i = 1; i <= 9; i ++) {
		cout << (x*i+9)/10 << " \n"[i==9];
	}
	return 0;
}