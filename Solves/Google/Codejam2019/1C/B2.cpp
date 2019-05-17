#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

vector<string> every;
unordered_map<string, int> possib;
set<pair<int, char> > memo;
vector<int> query;

void getRandom(int f) {
	query.clear();
	memo.clear();
	possib.clear();
	every.clear();
	string s = "ABCDE";

	do {
		possib[s] = 5;
		every.push_back(s);
	} while(next_permutation(s.begin(), s.end()));

	vector<int> all;
	for (int i = 1; i <= 595; i++) all.push_back(i);

	random_shuffle(all.begin(), all.end());
	for (int i = 0; i < f; i++) query.push_back(all[i]);
}

void tiraEsse(int pos, char c) {
	if (memo.find(make_pair(pos, c)) != memo.end()) return;

	for (string& s : every) {
		if (s[pos] != c) continue;
		possib[s] = max(possib[s] - 1, 0);
	}

	memo.insert(make_pair(pos, c));
}

string getAnswer() {
	vector<string> vec;

	for (auto p : possib) {
		int k = p.second;
		while(k--) vec.push_back(p.first);
	}

	assert((int)vec.size() > 0);

	int ind = rand()%((int)vec.size());
	return vec[ind];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	srand(time(NULL));

	int t, f; cin >> t >> f;
	for (int cases = 1; cases <= t; cases++) {
		getRandom(f);

		for (int i : query) {
			cout << i << endl;
			fflush(stdout);

			char c; cin >> c;
			assert(c != 'N');

			int pos = (i - 1) % 5;
			tiraEsse(pos, c);
		}

		cout << getAnswer() << endl;

		char ver; cin >> ver;
		assert(ver != 'N');
	}

	return 0;
}