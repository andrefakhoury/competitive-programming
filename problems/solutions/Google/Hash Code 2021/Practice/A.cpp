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
#define print(...) { print(__VA_ARGS__); print('\n'); }

const int MAXI = 1e9;
struct Answer {
	long long score = 0;
	vector<vector<int>> order = {};
	bool operator<(Answer const& rhs) const { return score < rhs.score; }
	bool operator>(Answer const& rhs) const { return score > rhs.score; }
};

struct Pizza {
	int id;
	vector<int> ingredients;
};

void solve_greedy(vector<Pizza> pizzas, int n2, int n3, int n4) {
	vector<int> people(n2 + n3 + n4, 4);
	for (int i = 0; i < n2; i++) people[i] = 2;
	for (int i = n2; i < n2 + n3; i++) people[i] = 3;

	int n = n2 + n3 + n4, m = (int) pizzas.size();

	Answer global;
	while(double(clock()) / CLOCKS_PER_SEC <= 5) {
		shuffle(people.begin(), people.end(), rng);
		shuffle(pizzas.begin(), pizzas.end(), rng);

		Answer answer;
		for (int i = 0, j = 0; i < n && j < m; i++) {
			if (j + people[i] - 1 >= m) continue;

			vector<int> used, id_pizzas;
			for (int count = 0; count < people[i]; count++) {
				id_pizzas.push_back(pizzas[j + count].id);
				for (int k : pizzas[j + count].ingredients) used.push_back(k);
			}

			sort(used.begin(), used.end());
			used.erase(unique(used.begin(), used.end()), used.end());

			answer.order.push_back(id_pizzas);
			answer.score += 1ll * used.size() * used.size();

			j += people[i];
		}

		if (answer > global) {
			cerr << "Found " << answer.score << endl;
			global = answer;
		}
	}

	cout << global.order.size() << "\n";
	for (vector<int>& v : global.order) {
		cout << v.size() << " ";
		for (int i : v) cout << i << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	int m, n[3]; rd(m, n[0], n[1], n[2]);

	vector<vector<string>> input(m);
	vector<string> allx;
	for (int i = 0; i < m; i++) {
		int k; rd(k);
		input[i].resize(k);
		for (string& x : input[i]) { rd(x); allx.push_back(x); }
	}
	sort(allx.begin(), allx.end());
	allx.erase(unique(allx.begin(), allx.end()), allx.end());

	vector<Pizza> pizzas(m);
	for (int i = 0; i < m; i++) {		
		pizzas[i].ingredients.resize(input[i].size());
		for (int j = 0; j < (int) pizzas[i].ingredients.size(); j++) {
			pizzas[i].ingredients[j] = lower_bound(allx.begin(), allx.end(), input[i][j]) - allx.begin();
		}
		sort(pizzas[i].ingredients.begin(), pizzas[i].ingredients.end());
		pizzas[i].id = i;
	}

	solve_greedy(pizzas, n[0], n[1], n[2]);
}