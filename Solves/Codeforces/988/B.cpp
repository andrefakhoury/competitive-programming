#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair

#define MAXN 105
#define MAXM 1000000005

typedef pair<int, int> pii;

bool compareLen(const string& a, const string& b) {
    return (a.size() < b.size()); 
}

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<string> s;
	vector<string> sau;
	string x, aux;
	for (int i = 0; i < n; i++) {
		cin >> x;
		s.pb(x);
	}

	sort(s.begin(), s.end(), compareLen);

	for (int i = 1; i < n; i++) {
		if (s[i].find(s[i-1]) == string::npos) {
			cout << "NO\n";
			return 0;
		}
	}
	
	cout << "YES\n";
	for (int i = 0; i < n; i++) {
		cout << s[i] << "\n";
	}
	
	return 0;
}

/*
abacaba
aba
aba
ba
a*/