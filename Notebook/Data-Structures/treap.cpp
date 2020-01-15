#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <typename T>
struct Treap {

	struct Node {
		T val;
		int h, sz;
		Node *L, *R;

		Node(T x) : val(x) {
			h = rng();
			sz = 1;
			L = R = nullptr;
		}

		friend ostream& operator<<(ostream& out, Node const& t) {
			if (t.L) out << *t.L;
			out << t.val << ' ';
			if (t.R) out << *t.R;
			return out;
		}

		~Node() {
			if (L) delete L;
			if (R) delete R;
		}
	};

	Node* root;

	Treap() : root(nullptr) {}
	~Treap() { if (root) delete root; }

	void go(Node* t) {
		if (!t) return;

		t->sz = 1;
		if (t->L) t->sz += t->L->sz;
		if (t->R) t->sz += t->R->sz;
	}

	void meld(Node*& t, Node *l, Node *r) {
		if (!l || !r) {
			t = l ? l : r;
			return;
		}

		if (l->h > r->h) meld(l->R, l->R, r), t = l;
		else			 meld(r->L, l, r->L), t = r;
		go(t);
	}

	void split(Node* t, Node*& l, Node*& r, T x) {
		if (!t) {
			l = r = nullptr;
			return;
		}

		if (x > t->val) split(t->R, t->R, r, x), l = t;
		else 			split(t->L, l, t->L, x), r = t;

		go(l), go(r);
	}

	void insert(Node *&t, Node *v) {
		if (!t) t = v;
		else {
			if (v->h > t->h) split(t, v->L, v->R, v->val), t = v;
			else if (t->val <= v->val) insert(t->R, v);
			else insert(t->L, v);
			go(t);
		}
	}

	void erase(Node*& t, T x) {
		if (!t) return;
		if (t->val == x) {
			Node* aux = t;
			meld(t, t->L, t->R);
			delete aux;
		} else if (t->val < x) erase(t->R, x);
		else erase(t->L, x);
		go(t);
	}

	T kth(Node *t, int k) {
		int qtt = 1;
		if (t->L) qtt += t->L->sz;

		if (qtt == k) return t->val;
		else if (k > qtt) return kth(t->R, k-qtt);
		else return kth(t->L, k);
	}

	int ord(Node* t, T val) {
		Node *aux = nullptr, *r = nullptr;
		split(root, aux, r, val);

		int ans = 0;
		if (aux) ans = aux->sz;
		meld(root, aux, r);

		return ans;
	}

	void insert(T val) {
		Node* aux = new Node(val);
		insert(root, aux);
	}

	void erase(T val) {
		erase(root, val);
	}

	void erase_range(T lo, T hi) {
		Node *l, *r, *aux;
		l = r = aux = nullptr;

		split(root, l, aux, lo);
		split(aux, aux, r, hi);
		delete aux;
		meld(root, l, r);
	}

	// kth smallest number (0 indexed)
	T kth(int k) {
		return kth(root, k+1);
	}

	// ord_of_key(x), also 0 indexed
	int ord(T x) {
		return ord(root, x);
	}

	friend ostream& operator<<(ostream& out, Treap const& tp) {
		if (tp.root) out << *tp.root;
		return out;
	}
};

int main() {
	Treap<int> tp;

	tp.insert(3);
	tp.insert(4);
	tp.insert(4);
	tp.insert(2);

	cout << tp << '\n';
	cout << tp.kth(0) << '\n';
	cout << tp.ord(3) << '\n';

	tp.erase(1);
	cout << tp << '\n';



}