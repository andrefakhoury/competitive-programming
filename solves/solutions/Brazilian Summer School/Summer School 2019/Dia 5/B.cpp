#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 100005;

int voc[MAXN];
bool isV[MAXN], isC[MAXN];
string s;

bool isVowel(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

bool isConsn(char c) {
	return !isVowel(c);
}

bool checkVocal(int i, int j) {
	return voc[j] - (i == 0 ? 0 : voc[i-1]) > 0;
}

int solve(int i, int j, bool rev) {
	if (i >= j) return 1;
	int l = !rev ? i : j;
	int r = !rev ? j : i;

	if (isC[l] && isV[r])
		return 0;
	if (isC[l] && isC[r])
		return !rev ? solve(i, j-1, rev) : solve(i+1, j, rev);
	if (isV[l] && isV[r])
		return !rev ? solve(i+1, j, !rev) : solve(i, j-1, !rev);

	int ret = !checkVocal(i+1, j-1);
	return ret + (!rev ? solve(i, j-1, rev) : solve(i+1, j, rev));
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	
	while(cin >> s) {
		s = '0' + s;

		for (int i = 1; i < s.size(); i++) {
			isV[i] = isVowel(s[i]);
			isC[i] = isConsn(s[i]);
			voc[i] = voc[i-1] + isVowel(s[i]);
		}

		cout << solve(1, s.size()-1, false) << "\n";
	}
}