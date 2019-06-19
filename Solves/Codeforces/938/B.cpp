#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	vector<int> a(n);

	for (int& i : a) cin >> i;

	vector<int> q1(n), q2(n);
	int last = 1;
	for (int i = 0; i < n; i++) {
		q1[i] = (a[i] - last);
		// last = a[i];
	}

	last = 1e6;
	for (int i = n-1; i >= 0; i--) {
		q2[i] = (last - a[i]);
		// last = a[i];
	}

	int ans = -1;
	for (int i = 0; i < n; i++) {
		ans = max(ans, min(q1[i], q2[i]));
	}

	cout << ans << endl;
}