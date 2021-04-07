#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) print(__VA_ARGS__), print('\n')

template<typename T>
struct Treap {
	struct Node {
		T val;
		int sz, h;
		Node *l, *r;

		Node(T const& val) : val(val), sz(1), h(rng()), l(nullptr), r(nullptr) {}

		inline void print_node(ostream& out) {
			if (l) l->print_node(out);
			out << val << " ";
			if (r) r->print_node(out);
		}
	};

	using ptr = Node*;

	ptr root;
	void op(ptr t) {
		if (!t) return;
		t->sz = 1;
		if (t->l) t->sz += t->l->sz;
		if (t->r) t->sz += t->r->sz;
	}

	ptr merge(ptr l, ptr r) {
		if (!l) return r;
		if (!r) return l;

		if (l->h > r->h) {
			l->r = merge(move(l->r), move(r));
			op(l.get());
			return l;
		} else {
			r->l = merge(move(l), move(r->l));
			op(r.get());
			return r;
		}
	}

	pair<ptr, ptr> split(ptr t, T const& v) {
		if (!t) return {};
		ptr x;
		if (t->val < v) {
			tie(t->r, x) = split(move(t->r), v);
			op(t.get());
			return {move(t), move(x)};
		} else {
			tie(x, t->l) = split(move(t->l), v);
			op(t.get());
			return {move(x), move(t)};
		}
	}

	pair<ptr, ptr> split_pos(ptr t, int pos) {
		if (!t) return {};
		int p = (t->l ? t->l->sz : 0) + 1;
		ptr x;
		if (pos >= p) {
			tie(t->r, x) = split_pos(move(t->r), pos-p);
            op(t.get());
            return {move(t), move(x)};
		} else {
			tie(x, t->l) = split_pos(move(t->l), pos);
            op(t.get());
            return {move(x), move(t)};
		}
	}

	void insert(T const& v) {
		ptr l, r;
		tie(l, r) = split(move(root), v);
		l = merge(move(l), make_unique<Node>(v));
		root = merge(move(l), move(r));
	}

	void insert_pos(T const& v, int pos) {
		ptr l, r;
		tie(l, r) = split_pos(move(root), pos);
		l = merge(move(l), make_unique<Node>(v));
		root = merge(move(l), move(r));
	}

	void erase(T const& v) {
		ptr l, r, aux;
		tie(l, aux) = split(move(root), v);
		tie(aux, r) = split_pos(move(aux), 1);
		root = merge(move(l), move(r));
	}

	bool contains(T const& v) {
		ptr cur = root.get();
		while(cur != nullptr) {
			if (cur->val == v) return true;
			else if (cur->val > v) cur = cur->l.get();
			else cur = cur->r.get();
		}
		return false;
	}




};

template<typename T>
ostream& operator<<(ostream& out, Treap<T>& t) {
	if (t.root) t.root->print_node(out);
	return out;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);

	Treap<int> t;
	t.insert(10);
	t.insert(1);

	t.insert(10);
	t.insert(1);

	t.erase(10);

	t.insert(10);
}