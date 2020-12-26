#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef pair<int, int> pii;

const int MAXN = 1e6 + 6;

unordered_map<string, vector<string> > edges;
unordered_map<string, vector<string> > invrs;
vector<int> dag[MAXN];

int qttR(string& s) {
	int ret = 0;
	for (char c : s) ret += c == 'r';
	return ret;
}

void toLower(string& s) {
	for (char& c : s)
		c = c >= 'A' && c <= 'Z' ? c + 32 : c;
}

vector<string> order;
unordered_map<string, bool> vis;
void dfsOrder(string& u) {
	vis[u] = true;
	for (string& v : edges[u])
		if (!vis[v]) dfsOrder(v);
	order.pb(u);
}

unordered_map<string, int> color;
vector<string> strColor[MAXN];

void dfsColor(string& u, int curColor) {
	color[u] = curColor;
	strColor[curColor].pb(u);

	for (string& v : invrs[u])
		if (!color[v]) dfsColor(v, curColor);
}

unordered_map<int, pii> memoColor;
pii getAns(int c) {
	if (memoColor.find(c) != memoColor.end()) 
		return memoColor[c];

	pii mini = {INT_MAX, INT_MAX};
	for (string& s : strColor[c]) {
		pii cur = {qttR(s), s.size()};
		mini = min(mini, cur);
	}

	return memoColor[c] = mini;
}

unordered_map<int, pii> memo;
pii dfs(int u) {
	if (memo.find(u) != memo.end()) return memo[u];

	memo[u] = getAns(u);
	for (int v : dag[u]) {
		memo[u] = min(memo[u], dfs(v));
	}

	return memo[u];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	unordered_set<string> allWords;

	int n; cin >> n;
	vector<string> essay(n);

	for (int i = 0; i < n; i++) {
		cin >> essay[i];
		toLower(essay[i]);
		allWords.insert(essay[i]);
	}

	int m; cin >> m;
	while(m--) {
		string s, t; cin >> s >> t;
		toLower(s); toLower(t);
		edges[s].pb(t);
		invrs[t].pb(s);

		allWords.insert(s);
		allWords.insert(t);
	}

	for (string u : allWords)
		if (!vis[u]) dfsOrder(u);
	reverse(order.begin(), order.end());

	int curColor = 0;
	for (string& u : order)
		if (!color[u]) dfsColor(u, ++curColor);

	map<pii, bool> created;
	for (string u : allWords) {
		int c = color[u];

		for (string& v : edges[u]) {
			pii edge = {c, color[v]};
			if (!created[edge]) dag[c].pb(color[v]);
			created[edge] = true;
		}
	}

	for (int c = 1; c <= curColor; c++) dfs(c);

	long long minR = 0, minS = 0;
	for (string& s : essay) {
		int c = color[s];
		pii cur = memo[c];

		minR += cur.first;
		minS += cur.second;
	}

	cout << minR << " " << minS << endl;

	return 0;
}