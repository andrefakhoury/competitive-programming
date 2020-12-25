#include <bits/stdc++.h>

#define ff first
#define ss second

#define pb push_back
#define eb emplace_back
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define clr(x, c) memset((x), (c), sizeof((x)))

using namespace std;

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl


using ll = long long;
using ii = pair<int, int>;

int const inf = 0x3f3f3f3f;
ll const linf = 0x3f3f3f3f3f3f3f3f;

int const mod = 1e9 + 7;

seed_seq seq {
		(uint64_t) chrono::duration_cast<chrono::nanoseconds>(
				chrono::high_resolution_clock::now().
						time_since_epoch()).count(),
		(uint64_t) __builtin_ia32_rdtsc(),
		(uint64_t) random_device{}(),
		(uint64_t) 17
};

mt19937 rd{seq};

int nq = 0, cach = 0;

map<tuple<int, int, int>, int> cache;

int query(int a, int b, int c) {
	if (a > b) swap(a, b);
	if (b > c) swap(b, c);
	if (a > b) swap(a, b);

	if (cache.count({a, b, c})) {
		cach++;
		return cache[{a, b, c}];
	}

	cout << "? " << a << ' ' << b << ' ' << c  << '\n' << flush;

	int x;
	cin >> x;

	nq++;
	return cache[{a, b, c}] = x;
}

void answer(int x) {
	cout << "! " << x << '\n' << flush;
	exit(0);
}

vector<int> find_pivots(int n) {
	auto red = [] (auto v) {
		vector<int> adds;
		for (int i = 0; i < (int)v.size()-2; i += 3) {
			adds.pb(query(v[i], v[i+1], v[i+2]));
		}

		sort(all(adds));
		adds.erase(unique(all(adds)), adds.end());

		vector<int> r;
		for (auto i : v) {
			if (!binary_search(all(adds), i)) {
				r.pb(i);
			}
		}
		return r;
	};

	vector<int> s(n);
	iota(all(s), 1);
	shuffle(all(s), rd);

	while ((int)s.size() >= 3) {
		s = red(s);
	}

	return s;
}

template<typename Iter, typename Func>
void quickselect(Iter l, Iter r, int k, Func&& cmp) {
	int n = r-l;
	if (n == 1) return;

	Iter pivot = l + uniform_int_distribution<int>(0, n-1)(rd);

	auto mid = partition(
			l, r,
			[&] (auto i) {
				return cmp(*pivot, i);
			}

	);

	int pos = mid-l;
	if (pos == k) return;
	else if (pos > k) quickselect(l, mid, k, cmp);
	else quickselect(mid, r, k - pos, cmp);
}

int main() {
	int n;
	cin >> n;

	vector<int> s(n);
	iota(all(s), 1);

	auto pivots = find_pivots(n);

	for (auto i : pivots) s.erase(find(all(s), i));

	shuffle(all(s), rd);

	nth_element(
			s.begin(),
			s.begin()+(n-2)/2,
			s.end(),
			[p = pivots[0]] (auto a, auto b) {
				int x = query(p, a, b);
				if (x == a) return true;
				else return false;
			}
	);

	answer(s[(n-2)/2]);
}