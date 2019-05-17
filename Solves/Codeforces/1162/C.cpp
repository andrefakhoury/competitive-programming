#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

int question[MAXN];
int n, k;

vector<int> app[MAXN];
int freq[MAXN];

bool check(int a, int b) {
	if (a == b) return freq[a] == 0;

	if (!freq[a] || !freq[b]) return true;

	int ida = app[a].front();
	int idb = app[b].back();

	return ida > idb;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> question[i];
		freq[question[i]]++;
		app[question[i]].pb(i);
	}

	long long ans = 0;
	for (int a = 1; a <= n; a++) {
		for (int b = max(a-1, 1); b <= min(a+1, n); b++) {
			ans += check(a, b);
		}
	}

	cout << ans << endl;
}