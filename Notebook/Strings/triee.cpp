#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
#define mset(x, y) memset(x, y, sizeof x)

int actual = 1;
int qtt[MAXN], term[MAXN], next[MAXN][256];
string s;

void add(int at, int i) {
	qtt[at]++;

	if (i == (int)s.size()) { //end of string
		term[at]++;
		return;
	}

	if (next[at][s[i]] == -1) { //needs to be created on graph
		next[at][s[i]] = actual++;
	}

	add(next[at][s[i]], i+1);
}

void remove(int at, int i) {
	qt[at]--;

	if (i == (int)s.size()) {
		term[at]--;
		return;
	}

	next[at][s[i]] = -1;

	remove(next[at][s[i]], i+1);
}

int main() {
	mset(next, -1);

	return 0;
}