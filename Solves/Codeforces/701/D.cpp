#include <bits/stdc++.h>
using namespace std;

#define eb emplace_back
#define pb push_back
#define mk make_pair
#define fi first
#define se second

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 1e5 + 5;


double get(double x, ll n, ll l, ll v1, ll v2, ll k) {

	double curPos = 0, ret = 0;
	while(n) {
		// eu vou pegar um onibus e dirigir td mundo nele
		double at = min(l - curPos, x) * v2;
		curPos += min(l - curPos, x) * v1;

		ret += min(l - curPos, x);
		n = max(0ll, n-k);
	}

	return ret;
}

int main() {
	ll n, l, v1, v2, k;
	scanf("%lld%lld%lld%lld%lld", &n, &l, &v1, &v2, &k);

	ll num = (n+k-1)/k;
	for (double x = 0; x <= l; x += 0.2) {
		cout << x << ": " << get(x, n, l, v1, v2, k) << endl;
	}

	// int cnt = 300;
	// while(cnt--) {
	// 	mi = (lo + hi) / 2.0;
	// 	if (v1*(l - mi) + v2 * mi < l) hi = mi;
	// 	else lo = mi;
	// }
		
	// cout << lo << endl;

	// double ans = lo + (l - lo*v2)/v1;
	// printf("%.7lf\n", ans);

	// return 0;
	
//	double ans = 0, cur = 0;
//	while(n) {
//		// vou pegar td mundo e jogar no onibus
//		double at = (l - cur) / double(v2);
//
//		// os caras restantes tem que andar com v1 por ans-cur metros
//		cur = v1 * at;
//		cur = min(cur, double(l));
//		n = max(0ll, n - k);
//
//		ans += at;
//	}
//
//	printf("%.7lf\n", ans);
//	
//	return 0;	
}
