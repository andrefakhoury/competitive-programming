const int MAXN = 1e5 + 5;

struct Trie {
	int terminal = 0;
	map<char, int> next;
};

vector<Trie> t(1);

void addTrie(string& s) {
	int v = 0;
	for (char c : s) {
		if (t[v].next.count(c) == 0) {
			t[v].next[c] = t.size();
			t.emplace_back();
		}
		v = t[v].next[c];
	}
	t[v].terminal++;
}

bool findTrie(string& s) {
	int v = 0;
	for (char c : s) {
		if (t[v].next.count(c) == 0) return false;
		v = t[v].next[c];
	}
	return t[v].terminal > 0;
}