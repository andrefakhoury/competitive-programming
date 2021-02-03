const int ALPHA_SIZE = 26;
struct Trie {
	int cnt, end_here;
	Trie* children[ALPHA_SIZE] = {};

	Trie() : children{}, cnt{}, end_here{} {}

	template<typename T> void add(T const& s, int i = 0) {
		if (i == (int) s.size()) end_here++;
		else {
			cnt++;
			if (children[s[i]] == NULL) children[s[i]] = new Trie();
			children[s[i]]->add(s, i + 1);
		}
	}

	template<typename T> void remove(T const& s, int i = 0) {
		if (i == (int) s.size()) end_here--;
		else {
			assert(children[s[i]] != NULL);
			cnt--;
			children[s[i]]->remove(s, i + 1);
		}
	}

	template<typename T> int count_equal(T const& s, int i = 0) {
		if (i == (int) s.size()) return end_here;
		if (children[s[i]] == NULL) return 0;
		return children[s[i]]->count_equal(s, i + 1);
	}

	template<typename T> int count_pref_equal(T const& s, int i = 0) {
		if (i == (int) s.size()) return end_here;
		if (children[s[i]] == NULL) return end_here;
		return end_here + children[s[i]]->count_pref_equal(s, i + 1);
	}
};