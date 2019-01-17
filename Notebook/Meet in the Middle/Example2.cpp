/*
	The 0-1 KnapSack problem, using the Meet in the Middle approach.
	The complexity is something like O(2^(n/2) * n/2).
	Useful if you have some maximum weight that inviabilize DP.
*/

#include <bits/stdc++.h>
using namespace std;

struct product {
	long long weight, price;
};

long long n, w; //number of elements, maximum weight
vector<product> a; //vector of products

void solve(int at, int l, int r, long long val, long long weight, vector<pair<long long, long long> >& v) {
	if (weight > w) return;

	//inserts in the vector
	v.push_back(make_pair(weight, val));

	//call all the possibilities
	if (at < r) {
		solve(at+1, l, r, val + a[at].price, weight + a[at].weight, v);
		solve(at+1, l, r, val, weight, v);
	}
}

int main() {
	scanf("%lld%lld", &n, &w);
	a.resize(n);

	for (int i = 0; i < n; i++)
		scanf("%lld%lld", &a[i].price, &a[i].weight);

	vector<pair<long long, long long> > X; //{total_weight, total_price}
	vector<pair<long long, long long> > Y;

	solve(0, 0, n/2, 0, 0, X); //first half
	solve(n/2, n/2, n, 0, 0, Y); //second half

	sort(Y.begin(), Y.end());
	
	//calculates the maximum possible price from 0-i
	vector<long long> maximum(Y.size());
	maximum[0] = Y[0].second;
	for (int i = 1; i < (int)maximum.size(); i++)
		maximum[i] = max(maximum[i-1], Y[i].second);

	//gets the answer to the problem, analysing the two formed sets
	long long ans = 0;
	for (int i = 0; i < (int)X.size(); i++) {
		int ind = lower_bound(Y.begin(), Y.end(), make_pair(w - X[i].first, 0LL)) - Y.begin() - 1;
		if (ind < 0) continue; //no element found
		
		//gets the maximum possible answer
		if (X[i].first + Y[ind].first <= w) ans = max(ans, X[i].second + maximum[ind]);
	}

	printf("%lld\n", ans);
	return 0;
}