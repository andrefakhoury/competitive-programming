#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int maxn = 5e6 + 5;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

namespace MaxStack {
ii st[maxn];

int r, topo;

void init() {
	r = topo = 0;
}

int get() {
	if (r == 0) return 0;
	return st[r-1].ff;
}

void push(int x) {
	if (r > 0 and st[r-1].ff >= x) topo++;
	else st[r++] = ii{x, topo++};
}

void pop() {
	if (r > 0 and st[r-1].ss == topo-1) r--;
	topo--;
}
}

namespace RNG {
	int n, p, q, m;
	unsigned int SA, SB, SC;
	unsigned int rng61(){
		SA ^= SA << 16;
		SA ^= SA >> 5;
		SA ^= SA << 1;
		unsigned int t = SA;
		SA = SB;
		SB = SC;
		SC ^= t ^ SA;
		return SC;
	}
	
	ll gen(){
		scanf("%d%d%d%d%u%u%u", &n, &p, &q, &m, &SA, &SB, &SC);

		MaxStack::init();

		ll ans = 0;
		for(int i = 1; i <= n; i++){
			if(rng61() % (p + q) < p) {
				// printf("PUSH : ");
				MaxStack::push(rng61() % m + 1);
			}
			else {
				// printf("POP : ");
				MaxStack::pop();
			}
			ans ^= ll(i)*MaxStack::get();
		}

		return ans;
	}
}

int main() {
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++) {
		ll ans = RNG::gen();
		printf("Case #%d: %lld\n", i, ans);
	}
	return 0;
}