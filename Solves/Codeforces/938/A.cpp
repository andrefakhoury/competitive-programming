#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e3 + 5;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	string s; cin >> s;

	for (int i = 0; i < s.size(); i++) {
		if (!isVowel(s[i])) cout << s[i];
		else {
			int j;
			for (j = i; j < s.size(); j++) {
				if (!isVowel(s[j])) break;
			}
			cout << s[i];
			i = j-1;
		}
	}

	cout << endl;
}