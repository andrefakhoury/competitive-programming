#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
typedef pair<int, int> pii;

bool isPrime[MAXN];
void sieve() {
	fill(isPrime, isPrime+MAXN, true);
	for (int i = 2; i < MAXN; i++) {
		if (isPrime[i]) for (int j = 2 * i; j < MAXN; j += i) isPrime[j] = false;
	}
}

pii divi(int n) {
	for (int i = 2; i <= n; i++) {
		if (n%i == 0 && isPrime[i]) return pii(i, n/i);
	}
	assert(0);
}

int main() {
	sieve();
	
	int t, cs = 0; scanf("%d", &t);
	while(t--) {
		int n, l; scanf("%d%d", &n, &l);

		map<int, char> mp;
		vector<pii> qry(l);
		set<int> primes;

		for (int i = 0; i < l; i++) {
			int x; scanf("%d", &x);
			qry[i] = divi(x);
			primes.insert(qry[i].first);
			primes.insert(qry[i].second);
		}

		assert(primes.size() == 26);

		char nxt = 'A';
		for (int p : primes) {
			mp[p] = nxt++;
		}

		printf("Case #%d: ", ++cs);

		int last, next;
		if (qry[0].first == qry[1].first || qry[0].first == qry[1].second) {
			printf("%c", mp[qry[0].second]);
			last = qry[0].second;
			next = qry[0].first;
		} else {
			printf("%c", mp[qry[0].first]);
			last = qry[0].first;
			next = qry[0].second;
		}

		for (int i = 1; i < l; i++) {
			if (qry[i].first == last) {
				printf("%c", mp[qry[i].second]);
				last = qry[i].second;
				next = qry[i].first;
			} else {
				printf("%c", mp[qry[i].first]);
				last = qry[i].first;
				next = qry[i].second;				
			}
		}

		printf("\n");
	}
}