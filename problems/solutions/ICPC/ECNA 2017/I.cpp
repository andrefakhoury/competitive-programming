#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
#define deb(x) (cout << #x << ": " << x << endl)

const int N = 1000007, inf = 0x3f3f3f3f;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int inv(vector<ii> vec) {
	int tot = 0;
	for(int i = 0; i < (int) vec.size(); i++) {
		for(int j = i+1; j < (int) vec.size(); j++) {
			tot += vec[j].se < vec[i].se;
		}
	}
	return tot;
}

int v[5];

int oper(int a, int b, int x) {
	if(a == inf or b == inf) return inf;
	if(x == 0) { // soma
		return a + b;
	} else if(x == 1) { // sub
		return a - b;
	} else if(x == 2) { // mul
		return a * b;
	} else { // div
		if(b == 0 or a%b != 0) return inf;
		return a/b;
	}
}

ii merge(ii a, ii b, int x) {
	// cout << x << ' ';
	return ii(oper(a.fi, b.fi, x), a.se + b.se);
}


struct turci {
	vector<ii> v;
	int op;
	turci(){}
	turci(int x, int op) {
		v.push_back(ii(x, 0));
		this->op = op;
	}
	turci operator * (turci t) const {
		turci ans;
		ans.op = t.op;
		for(int i = 0; i < (int) v.size(); ++i) {
			for(int j = 0; j < (int) t.v.size(); ++j) {
				ans.v.push_back(merge(v[i], t.v[j], op));
			}
		}
		return ans;
	}

	turci operator + (turci t) const {
		turci ans;
		ans.op = op;
		ans.v = v;
		for(ii x : t.v) ans.v.push_back(x);
		return ans;
	}

	turci operator ^(int a) {
		turci ans;
		ans.op = op;
		ans.v = v;
		for(ii & x : ans.v) x.se += a;
		return ans;
	}
};
vector<int> ma;

turci lista(vector<turci> vec) {
	// vezes e divisao
	for(int i = 0; i + 1 < (int) vec.size(); ++i) {
		if(vec[i].op > 1) {
			vec[i] = vec[i] * vec[i+1];
			vec.erase(vec.begin() + i + 1);
			i--;
		}
	}

	// soma e sub
	turci ans = vec[0];
	for(int i = 1; i < (int) vec.size(); ++i) {
		ans = ans * vec[i];
	}
	return ans;
}
turci solve2(int l, int r) {
	int tam = r - l + 1;

	if(tam == 1) {
		return turci(v[l], ma[l]);
	} else if(tam == 2) {
		return solve2(l, l) * solve2(r, r);
	} else if(tam == 3) {
		turci ans = lista({solve2(l, l), solve2(l+1, l+1), solve2(l+2, l+2)});

		ans = ans + (solve2(l, l) * solve2(l+1, r) ^ 1);
		ans = ans + (solve2(l, l+1) * solve2(r, r) ^ 1);
		return ans;
	} else {
		turci ans = lista({solve2(l, l), solve2(l+1, l+1), solve2(l+2, l+2), solve2(l+3, l+3)});
		// if(ma[0] == 2 and ma[1] == 0 and ma[2] == 2 and v[0] == 3 and v[1] == 6 and v[2] == 2 and v[3] == 3) cout << aux.fi << endl;
		ans = ans + (solve2(l, l) * solve2(l+1, r)^1);
		ans = ans + (solve2(l, r-1) * solve2(r, r)^1);
		ans = ans + (solve2(l, l+1) * solve2(r-1, r)^2);
		ans = ans + (lista({solve2(l, l), solve2(l+1, l+1), solve2(r-1, r)})^1);
		ans = ans + (lista({solve2(l, l+1), solve2(r-1, r-1), solve2(r, r)})^1);
		ans = ans + (lista({solve2(l, l), solve2(l+1, r-1), solve2(r, r)})^1);

		return ans;
	}
}
int solve(int l, int r) {
	turci res= solve2(l, r);

	// deb(res.v.size());
	int ans = inf;
	for(int i = 0; i < (int) res.v.size(); ++i) {
		if(res.v[i].fi == 24) ans = min(ans, res.v[i].se);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	for(int i = 0; i < 4; i++) {
		cin >> v[i];
	}

	vector<vector<int> > op;

	for(int i = 0; i < 4 * 4 * 4; ++i) {
		vector<int> mask;
		int k = i;

		for(int j = 0; j < 3; ++j) {
			mask.pb(k%4);
			k /= 4;
		}
		op.pb(mask);
	}

	vector<ii> pos(4);
	for(int i = 0; i < 4; i++) {
		pos[i] = ii(v[i], i);
	}

	int ans = inf;
	sort(pos.begin(), pos.end());
	do {
		int in = inv(pos);
		// deb(in);
		for(int i = 0; i < 4; ++i) {
			v[i] = pos[i].fi;
			// cout << v[i] << ' ';
		}
		for(int j = 0; j < 64; ++j) {
			::ma = op[j];
			ma.push_back(0);
			ans = min(ans, solve(0, 3) + in);
		}
	} while(next_permutation(pos.begin(), pos.end()));

	assert(ans < inf);

	if(ans == inf) cout << "impossible" << endl;
	else cout << ans << endl;
}
