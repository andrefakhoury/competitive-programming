#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fi first
#define se second

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1000007, inf = 0x3f3f3f3f;

struct no {
	map<char, int> ch;
	int idx;
};

int tt;
int vert[N];
no trie[N];
vector<int> e[N];

void add(string & s, int idx) {
	int cur = 0;
	for(char c : s) {
		if(trie[cur].ch.count(c) == 0) {
			trie[cur].ch[c] = ++tt;
			trie[tt].idx = inf;
			e[cur].pb(tt);
			e[tt].pb(cur);
		}
		cur = trie[cur].ch[c];
	}
	trie[cur].idx = idx;
	vert[idx] = cur;
}

int add2(string & s) {
	int cur = 0;
	int l = 0;
	for(char c : s) {
		if(trie[cur].ch.count(c) == 0) {
			trie[cur].ch[c] = ++tt;
			trie[tt].idx = inf;
			e[cur].pb(tt);
		}
		cur = trie[cur].ch[c];
	}
	return cur;
}


int pre(int u) {
	int men = trie[u].idx;
	for(auto & [c, v] : trie[u].ch) {
		men = min(men, pre(v));
	}
	if(u != 0) e[u].pb(vert[men]);
	return men;
}

int que[N], d[N];

void bfs() {
	queue<int> q;
	memset(d, -1, sizeof d);
	q.push(0);
	d[0] = 0;

	while(q.size()) {
		int u = q.front();
		q.pop();

		for(int v : e[u]) {
			if(d[v] == -1) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;

    for(int i = 0; i < n; ++i) {
    	string s; cin >> s;
    	add(s, i);
    }

    trie[0].idx = inf;


    pre(0);
    for(int i = 0; i < m; ++i) {
    	string s; cin >> s;
    	que[i] = add2(s);
    }

    bfs();
    for(int i = 0; i < m; ++i) {
    	cout << d[que[i]] << '\n';
    }
}