#include <bits/stdc++.h>

#define deb(x) (cout << #x << ": " << x << endl)
#define pb push_back
#define fi first
#define se second
#define eb emplace_back
#define mid ((l+r) >> 1)
#define mst jdklsjd

const int M = 1e9 + 7;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 7;

ll x[N], y[N];
ll L[N], R[N];
ll pot[(int)1e6 + 8];


vector<int> id;

vector<ii> mst[4 * N];


void build(int p, int l, int r) {
	if(l == r) {
		auto aux = make_pair(R[id[l]], id[l]);
		mst[p].eb(aux);
	} else {
		build(2 * p, l, mid);
		build(2 * p + 1, mid+1, r);
		mst[p].resize(mst[2 * p].size() + mst[2 * p + 1].size());
		merge(mst[2 * p].begin(), mst[2 * p].end(), mst[2 * p + 1].begin(), mst[2 * p + 1].end(), mst[p].begin());
	}
}

vector<int> aux;
// l tem que ser >= do que ll, r = tem que ser menor do que rr
void query(int p, int l, int r, ll Ll, ll rr) {
	if(L[id[r]] < Ll) return;
	if(L[id[l]] >= Ll) {
		for(int i = mst[p].size()-1; i >= 0; --i) {
			if(mst[p][i].fi < rr) break;
			aux.pb(mst[p][i].se);
		}
	} else {
		query(2 * p, l, mid, Ll, rr);
		query(2 * p + 1, mid+1, r, Ll, rr);
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, q; cin >> n >> q;

	pot[0] = 1;
	for(int i = 1; i < 1e6 + 7; ++i) {
		pot[i] = pot[i-1] * 5782344ll % M;
	}

	vector<ll> vecL, vecR;
	for(int i = 0; i < n; ++i) {
		cin >> x[i] >> y[i];
		R[i] = x[i] - 2 * y[i]; // tem que ser maior do que esse
		L[i] = x[i] + 2 * y[i]; // tem que ser maior do que esse
		vecL.pb(L[i]);
		vecR.pb(R[i]);

		// deb(i);
		// deb(L[i]);
		// deb(R[i]);
		// cout << endl;
	}



	sort(vecL.begin(), vecL.end());
	vecL.erase(unique(vecL.begin(), vecL.end()), vecL.end());

	sort(vecR.begin(), vecR.end());
	vecR.erase(unique(vecR.begin(), vecR.end()), vecR.end());

	for(int i = 0; i < n; ++i) {
		R[i] = lower_bound(vecR.begin(), vecR.end(), R[i]) - vecR.begin();
		L[i] = lower_bound(vecL.begin(), vecL.end(), L[i]) - vecL.begin();
	}

	id.resize(n);
	iota(id.begin(), id.end(), 0);
	sort(id.begin(), id.end(), [&](int p, int q) {
		return L[p] < L[q]; // ordena os ids pelo L
	});


	build(1, 0, n-1);

	ll ans = 0;
	while(q--) {
		ll a, b; cin >> a >> b;

		ll x = -1 - ((ans+a)%M);
		ll y = (ans+b)%M;

		// cout << x << ' ' << y << endl;
		// deb(x);
		// deb(y);

		ll pos1 = x + 2 * y;
		ll pos2 = x - 2 * y;
		// deb(pos1);
		// deb(pos2);
		// os caras tem que ser maiores ou iguais que pos1
		// os caras tem que ser maiores ou iguais que pos2

		pos1 = lower_bound(vecL.begin(), vecL.end(), pos1) - vecL.begin();
		pos2 = lower_bound(vecR.begin(), vecR.end(), pos2) - vecR.begin();
		// deb(pos1);
		// deb(pos2);
		query(1, 0, n-1, pos1, pos2);

		sort(aux.begin(), aux.end());

		ans = 0;
		int j = 0;
		for(int i : aux) {
			// cout << i+1 << ' ';
			ans += pot[j] * (i+1) % M;
			if(ans >= M) ans -= M;
			j++;
		}
		// cout << endl;

		aux.clear();
		cout << ans << '\n';
	}
}