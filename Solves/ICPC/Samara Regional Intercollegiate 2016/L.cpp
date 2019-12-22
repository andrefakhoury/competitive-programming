#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<int, int> pii;

int solve(vector<int> v1, vector<int> v2) {
	set<int> a;
	set<int, greater<int>> b;
	for (int i : v1) a.insert(i);
	for (int i : v2) b.insert(i);

	int w1 = 0, w2 = 0;
	for (int i : v1) {
		auto it = b.upper_bound(i);
		if (it == b.end()) {
			it = b.begin();
			w2++;
		} else w1++;
		b.erase(it);
	}

	if (w1 < w2) return 2;
	if (w2 < w1) return 1;
	return 0;
}

int main() {
	int n; scanf("%d", &n);

	vector<int> a(n), b(n);
	for (int& i : a) scanf("%d", &i);
	for (int& i : b) scanf("%d", &i);

	int w1 = solve(a, b), w2 = solve(b, a);

	int A = (w1 == 1) + (w2 == 2);
	int B = (w1 == 2) + (w2 == 1);

	if (A > B) printf("First\n");
	else if (A < B) printf("Second\n");
	else if (!A) printf("None\n");
	else printf("Both\n");
}