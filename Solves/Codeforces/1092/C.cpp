#include <bits/stdc++.h>
using namespace std;

typedef pair<string, int> psi;
char ans[500];
vector<psi> s;
int n; 

bool cmp(psi& a, psi& b) {
	return a.first.size() < b.first.size();
}

bool cmp2(psi& a, psi& b) {
	return a.second < b.second;
}

// a ab
bool isPrefix(string& a, string& b) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] != b[i]) return false;
	return true;
}

// a ab
bool isSufix(string& a, string& b) {
	for (int i = a.size()-1, j = b.size()-1; i >= 0; i--, j--)
		if (a[i] != b[j]) return false;
	return true;		
}

bool check(string test) {
	memset(ans, 0, sizeof ans);
	for (int i = 0; i < s.size(); i += 2) {
		if (isPrefix(s[i].first, test) && isSufix(s[i+1].first, test)) {
			ans[s[i].second] = "P";
			ans[s[i+1].second] = "S";
		} else if (isSufix(s[i].first, test) && isPrefix(s[i+1].first, test)) {
			ans[s[i].second] = "S";
			ans[s[i+1].second] = "P";
		} else return false;
	}
	return true;
}

void printAndExit() {
	sort(s.begin(), s.end(), cmp2);
	for (int i = 0; i < 2*n-2; i++)
		printf("%c", ans[s[i].second]);
	printf("\n");
	exit(0);
}

int main() {
	cin >> n;

	s.resize(2*n-2);
	for (int i = 0; i < 2*n-2; i++) {
		cin >> s[i].first;
		s[i].second = i;
	}
	sort(s.begin(), s.end(), cmp);

	string x1 = s[0].first;
	string y1 = s[1].first;
	string xN = s[2*n-3].first;
	string yN = s[2*n-4].first;

	if (check(x1+xN)) printAndExit();
	if (check(x1+yN)) printAndExit();
	if (check(y1+xN)) printAndExit();
	if (check(y1+yN)) printAndExit();

	return 0;
}