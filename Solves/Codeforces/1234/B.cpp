#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> pii;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	int n, k; cin >> n >> k;

	set<int> all;
	deque<int> q;


	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (all.count(x)) {
			continue;
		} else {
			if (q.size() == k) {
				int r = q.back();
				all.erase(r);
				q.pop_back();

				q.push_front(x);
				all.insert(x);
			} else {
				q.push_front(x);
				all.insert(x);
			}
		}
	}

	cout << q.size() << '\n';
	for (int x : q) cout << x << ' ';
	cout << '\n';

	return 0;
}