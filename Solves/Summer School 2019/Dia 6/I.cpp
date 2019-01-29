#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 500005;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1.0);

string str[MAXN];
int n;
int last[MAXN];

void solve() {
	for (int i = n; i > 1; i--) {

		bool tudoIgual = true;
		for (int j = 1; j < last[i]; j++) {
			if (last[i-1] < j) {
				break;
			}


			if (str[i][j] != str[i-1][j]) tudoIgual = false;
			if (str[i][j] > str[i-1][j]) break;

			if (str[i][j] < str[i-1][j]) {
				last[i-1] = j;
				break;
			}
		}

		if (tudoIgual) last[i-1] = min(last[i-1], last[i]);
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> str[i];
		last[i] = str[i].size();
	}

	solve();

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < last[i]; j++) {
			cout << str[i][j];
		}
		cout << "\n";
	}

	return 0;
}