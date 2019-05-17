#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> pii;
typedef long long ll;

const int MAXN = 1e5 + 5;

char who[MAXN];
ll finish[MAXN];

struct cliente {
	ll id, t, d;
	cliente() {}
	cliente(ll a, ll b, ll c) {
		id = a, t = b, d = c;
	}

	void scan(ll i) {
		id = i;
		cin >> t >> d;
	}

	bool operator<(cliente& p) const{
		if (t == p.t) {
			return id < p.id;
		} else return t < p.t;
	}
};

struct pedido {
	ll t_in, t_out, id;

	pedido() {}
	pedido(ll a, ll b, ll c) {
		t_in = a, t_out = b, id = c;
	}
};

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	ll n, k; cin >> n >> k;
	vector<cliente> vec(n);

	for (int i = 0; i < n; i++) vec[i].scan(i);
	sort(vec.begin(), vec.end());

	queue<pedido> A, B;
	ll last_A = -1, last_B = -1;

	for (cliente& cl : vec) {
		while(A.size()) {
			pedido p = A.front();

			if (p.t_out <= cl.t) {
				A.pop();
			} else break;
		}

		while(B.size()) {
			pedido p = B.front();

			if (p.t_out <= cl.t) {
				B.pop();
			} else break;
		}

		last_A = max(last_A, cl.t);
		last_B = max(last_B, cl.t);

		if (A.size() <= B.size()) {
			who[cl.id] = 'A';
			finish[cl.id] = last_A + cl.d;
			A.emplace(last_A, last_A + cl.d, cl.id);

			last_A += cl.d;
		} else {
			who[cl.id] = 'B';
			finish[cl.id] = last_B + k * cl.d;
			B.emplace(last_B, last_B + k * cl.d, cl.id);

			last_B += k * cl.d;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << who[i] << ' ' << finish[i] << '\n';
	}

}