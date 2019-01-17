#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 100005;

bool test(string& s) {
	int n = s.size()-1;
	for (int i = 0, j = n; i < j; i++, j--) {
		if (s[i] != s[j]) return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	string s; 

	while(n--) {
		cin >> s;
		sort(s.begin(), s.end());
		if (test(s)) cout << -1 << "\n";
		else cout << s << "\n";
	}

	return 0;
}