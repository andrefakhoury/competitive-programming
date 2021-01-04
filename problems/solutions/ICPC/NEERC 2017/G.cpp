#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define pb push_back
#define fi first
#define se second
#define eb emplace_back

const int N = 1000007, inf = 0x3f3f3f3f;

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update>;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int A[N], B[N], C[N], D[N], E[N];
ll accE[N], accB[N];

int n, r;

inline ll count1(ll x) {
	if(n < 2 * r) return 0;
	ord_set<pair<ll, int> > st;
	ll sum = 0;

	// coloca sum
	for(int i = 1; i <= r; ++i) {
		sum += B[i];
	}
	

	ll sum2 = 0;
	
	// coloca sum2 menos o ultimo
	for(int i = r+1; i < r + r; ++i) {
		sum2 += B[i];
	}

	int cur = 0;
	st.insert(make_pair(sum, cur++));
	ll ans = 0;
	for(int i = r+1; i + r - 1 <= n; ++i) {
		sum2 += A[i + r - 1]; // coloca o ultimo do sum2

		// sum1 + sum2 <= x
		ans += st.order_of_key(make_pair(x - sum2, 0x3f3f3f3f)); // conta quantos sao menores ou iguais

		// atualiza o sum1
		sum += A[i];
		sum -= A[i - r];
		st.insert(make_pair(sum, cur++));
		
		sum2 -= A[i]; // retira o primeiro do sum2
	}


	return ans;
}

inline ll count2(ll x) {
	// poe tudo no set
	ord_set<pair<ll, int> > st;

	int cur = 0;
	ll ans = 0;
	// fixa o inicio do C, que tambem eh o inicio do B2
	for(int i = 1; i + r - 1 <= n; ++i) {
		ll aux = accB[i + r - 1] - accB[max(i - r, 1) - 1]; // quantos vou somar se o intervalo de C for zero
		// aux + soma de E <= x => soma de E <= x - aux => accE[j] - accE[i-1] <= x - aux => acc[j] <= x + accE[i-1] - aux
		// j >= max(i, r) e j <= i + r - 1
		ans += st.order_of_key(make_pair(x + accE[i-1] - aux, 0x3f3f3f3f)); // conta quantos sao menores ou iguais
		if(i >= r) {
			st.erase(st.lower_bound(make_pair(accE[i], 0)));
		}
		st.insert(make_pair(accE[i + r - 1], cur++));
	}
	return ans;
}

// conta quantos sao menores ou iguais que x
inline ll count(ll x) {
	// tamanho de C é vazio
	
	return count1(x) + count2(x);

}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
	ll k;

    
    cin >> n >> r >> k;

    ll suma = 0;
    for(int i = 1; i <= n; ++i) cin >> A[i], suma += A[i];
    for(int i = 1; i <= n; ++i) cin >> B[i], B[i] -= A[i];
    for(int i = 1; i <= n; ++i) cin >> C[i], C[i] -= A[i];
    
    for(int i = 1; i <= n; ++i) D[i] = B[i] + (i - r > 0? B[i-r] : 0);
    for(int i = 1; i <= n; ++i) {
    	E[i] = C[i] - D[i];
    }

    for(int i = 1; i <= n; ++i) { // constroi o acc de B e E
    	accB[i] = accB[i-1] + B[i];
    	accE[i] = accE[i-1] + E[i];
    }

    ll lo = 0, hi = 1e16;
    ll ans = 0;
    while(lo <= hi) {
    	ll mid = lo + (hi - lo)/2;
    	if(count(mid) < k) {
    		lo = mid+1;
    	} else {
    		hi = mid-1;
    		ans = mid;
    	}
    }

    cout << suma + ans << endl;

}