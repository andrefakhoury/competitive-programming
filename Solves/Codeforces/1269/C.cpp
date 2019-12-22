#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 1e5 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector<int> need;
string t, s;
int n, k;

int check() {
	for (int i = 0, ok = 0; !ok && i < n; i++) {
		if (t[i] > s[i]) ok = 1;
		else if (t[i] < s[i]) return i;
	}

	return -1;
}

void prop() {
	for (int i = 0; i < n-k; i++) t[i+k] = t[i];
}

void print() {
	
	cout << n << '\n' << t << '\n';
	exit(0);
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> k >> s;
	t = s;

	prop();

	int c = check();
	if (c == -1) print();

	int who = 0;
	for (int i = 0; i <= c; i++) {
		if (t[i] == '9' || s[i] == '9') continue;
		who = max(who, i%k);
	}

	t[who]++;
	for (int i = who+1; i < n; i++) t[i] = '0';
	prop();

	print();

	return 0;
}