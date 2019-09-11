// https://www.hackerearth.com/pt-br/practice/algorithms/searching/binary-search/practice-problems/algorithm/kriti-and-her-birthday-gift/

// frequence of string s in interval l..r

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
const int BKSZ = (int)sqrt(MAXN);

class Query {

public:
	int id, l, r;
	string s;

	Query() {}
	Query(int id, int l, int r, string s) {
		this->id = id;
		this->l = l;
		this->r = r;
		this->s = s;
	}

	bool operator< (const Query& b) const {
		if (l/BKSZ == b.l/BKSZ) return r < b.r;
		return l/BKSZ < b.l/BKSZ;
	}
};

class Mo {
	int n, q;
	vector<string> vec;
	vector<Query> qry;
	unordered_map<string, int> freq;

public:
	Mo() {}
	Mo(vector<string>& vec) {
		this->vec = vec;
		this->q = 0;
	}

	void addQuery(int l, int r, string& s) {
		qry.push_back(Query(q++, l, r, s));
	}

	void add(int id) {
		freq[vec[id]]++;
	}

	void remove(int id) {
		freq[vec[id]]--;
		if (freq[vec[id]] == 0) freq.erase(vec[id]);
	}

	int getAnswer(string& s) {
		if (freq.count(s)) return freq[s];
		return 0;
	}

	vector<int> MoAlgorithm() {
		vector<int> ans(q);
		sort(qry.begin(), qry.end());

		int l = 1, r = 0;
		for (int i = 0; i < (int)qry.size(); i++) {
			while (r < qry[i].r) add(++r);
			while (r > qry[i].r) remove(r--);
			while (l < qry[i].l) remove(l++);
			while (l > qry[i].l) add(--l);

			ans[qry[i].id] = getAnswer(qry[i].s);
		}

		return ans;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<string> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	Mo mo(a);
	int q; cin >> q;

	while(q--) {
		int l, r; cin >> l >> r;
		string s; cin >> s;
		mo.addQuery(l-1, r-1, s);
	}
	
	vector<int> ans = mo.MoAlgorithm();
	for (int i : ans) cout << i << "\n";

	return 0;
}