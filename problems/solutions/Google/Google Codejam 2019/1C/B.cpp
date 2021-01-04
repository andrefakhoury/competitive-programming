#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef long long ll;

vector<string> every;
set<string> elem;

void getRandom() {
	elem.clear();
	string s = "ABCDE";

	do {
		elem.insert(s);
		every.push_back(s);
	} while(next_permutation(s.begin(), s.end()));
}

void erase(int pos, char c) {
	for (string s : elem) {
		if (s[pos] != c) elem.erase(s);
	}
}

string getAnswer() {
	vector<string> vec;
	for (string s : elem) vec.push_back(s);
	assert(vec.size());
	int ind = rand()%(int)(vec.size());
	return vec[ind];
}

vector<int> getQuery() {
	vector<int> ret;
	for (int i = 1; i <= 119; i++) ret.push_back(i);
	// random_shuffle(ret.begin(), ret.end());

	// vector<int> ans;
	// for (int i = 0; i < 119; i++) ans.push_back(ret[i]);
	return ret;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	srand(time(NULL));

	int t, f; cin >> t >> f;
	for (int cases = 1; cases <= t; cases++) {
		getRandom();

		for (int i = 1; i <= 3; i++) {
			vector<int> chute = getQuery();

			map<char, int> qtt;
			for (int j : chute) {
				cout << ((j-1)*5 + i) << endl; fflush(stdout);
				char c; cin >> c;

				assert(c != 'N');

				qtt[c]++;
			}

			for (char c = 'A'; c <= 'E'; c++) {
				if (qtt[c] < 11) {
					erase(i-1, c);
				}
			}			
		}

		cout << getAnswer() << endl;

		char ver; cin >> ver;
		assert(ver != 'N');
	}

	return 0;
}