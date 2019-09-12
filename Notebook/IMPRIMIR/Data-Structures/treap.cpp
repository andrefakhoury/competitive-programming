#include <bits/stdc++.h>

using namespace std;

template <typename T>
class Treap {
private:
	struct Node
	{
		T val;
		int h, sz;
		Node *l, *r;

		Node(T x)
			: val(x), h(rand()), sz(1), l(nullptr), r(nullptr) {};

		friend ostream& operator<<(ostream& out, Node const& t)
		{
			if (t.l) out << *t.l;
			out << t.val << " ";
			if (t.r) out << *t.r;
			return out;
		}
	};

	void op(Node *t)
	{
		if (!t) return;
		t->sz = 1;
		if (t->l) t->sz += t->l->sz;
		if (t->r) t->sz += t->r->sz;	
	}

	void merge(Node *&t, Node *l, Node *r)
	{
		if (!l or !r)
			return void(t=l?l:r);
		if (l->h > r->h)
			merge(l->r, l->r, r), t = l;
		else
			merge(r->l, l, r->l), t = r;
		op(t);
	}

	void split(Node *t, Node *&l, Node *&r, T v)
	{
		if (!t) return void(l=r=nullptr);
		if (v > t->val)
			split(t->r, t->r, r, v), l = t;
		else 
			split(t->l, l, t->l, v), r = t;
		op(l), op(r);
	}

	void insert(Node *&t, Node *v)
	{
		if (!t) return void(t=v);
		if (v->h > t->h) split(t, v->l, v->r, v->val), t = v;
		else if (t->val <= v->val) insert(t->r, v);
		else insert(t->l, v);
		op(t);
	}

	void erase(Node *&t, T v)
	{
		if (!t) return;
		if (t->val == v) {
			Node *aux = t;
			merge(t, t->l, t->r);
			delete aux;
		}
		else if (t->val < v) erase(t->r, v);
		else erase(t->l, v);
		op(t);
	}

	T kth(Node *t, int pos)
	{
		int p = 1;
		if (t->l) p += t->l->sz;

		if (p == pos) return t->val;
		if (pos > p) return kth(t->r, pos-p);
		else return kth(t->l, pos);
	}

	int ord(Node *t, T val)
	{
		Node *aux = nullptr, *r = nullptr;
		split(root, aux, r, val);
		
		int ans = 0;
		if (aux) ans = aux->sz;
		
		merge(root, aux, r);
		return ans;
	}

	void del(Node *t)
	{
		if (t->l) del(t->l);
		if (t->r) del(t->r);
		delete t;
	}

	Node *root;

public:
	void insert(T val)
	{
		Node *aux = new Node(val);
		insert(root, aux);
	}

	template <typename... Args>
	void insert(T val, Args... args)
	{
		insert(val);
		insert(args...);
	}

	void erase(T val)
	{
		erase(root, val);
	}

	template <typename... Args>
	void erase(T val, Args... args)
	{
		erase(val);
		erase(args...);
	}

	void erase_range(T ini, T fim)
	{
		Node *l = nullptr, *r = nullptr, *aux=nullptr;
		split(root, l, aux, ini);
		split(aux, aux, r, fim);
		del(aux);
		merge(root, l, r);
	}

	T kth(int pos)
	{
		return kth(root, pos+1);
	}

	int ord(T val)
	{
		return ord(root, val);
	}

	friend ostream& operator<<(ostream& out, Treap const& tp)
	{
		if (!tp.root) return out;
		out << *tp.root;
		return out;
	}

	Treap()
	{
		root = nullptr;
	}

	~Treap()
	{
		if (root) del(root);
	}
};

int main()
{
	Treap<int> tp;

	tp.insert(3, 1, 5);
	cout << tp << "\n";

	tp.erase(3);
	cout << tp << "\n";
	
	tp.insert(2, 3, 4);
	cout << tp << "\n";
	
	cout << tp.kth(4) << "\n";
	cout << tp.ord(5) << "\n";

	tp.erase_range(2, 5);
	cout << tp << "\n";
}