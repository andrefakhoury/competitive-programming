#include <bits/stdc++.h>
using namespace std;

struct node {
	map<char, int> ch;
	int cnt, suf, end;
};

int tt;
node aho[N * 27];

void add(string & s) {
	int cur = 0;
	for(char c : s) {
		if(aho[cur].ch.count(c) == 0) aho[cur].ch[c] = ++tt;
		cur = aho[cur].ch[c];
	}

	aho[cur].end++;
}

void calc() {
	queue<tuple<int, int, int> > q;
	for(int i = 0; i < 26; ++i) {
		if(aho[0].ch.count('a' + i)) q.push({aho[0].ch['a' + i], 0, 'a' + i});
	}

	while(q.size()) {
		int u, p, c;
		tie(u, p, c) = q.front();
		q.pop();

		if(p) {
			p = aho[p].suf;
			while(p and aho[p].ch.count(c) == 0) p = aho[p].suf;
			if(aho[p].ch.count(c)) aho[u].suf = aho[p].ch[c];
		}

		aho[u].cnt = aho[u].end + aho[aho[u].suf].cnt;

		for(auto aux : aho[u].ch) {
			q.push({aux.se, u, aux.fi});
		}
	}
}