#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool valid(string& x) {
	return x[0] >= 1 && x[0] <= 8 &&
		   x[1] >= 1 && x[1] <= 8;
}

vector<string> position(string& x) {
	vector<string> ret;
	string a;

	a = x;
	a[0] -= 2;
	a[1] -= 1;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] -= 1;
	a[1] -= 2;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] -= 2;
	a[1] += 1;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] -= 1;
	a[1] += 2;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] += 2;
	a[1] -= 1;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] += 1;
	a[1] -= 2;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] += 2;
	a[1] += 1;
	if (valid(a)) ret.push_back(a);

	a = x;
	a[0] += 1;
	a[1] += 2;
	if (valid(a)) ret.push_back(a);

	return ret;
}

int solve(string& a, string& b) {
	map<string, int> dist;
	priority_queue<pair<int, string> > pq;
	pq.push({0, a});
	dist[a] = 0;

	while (pq.size()) {
		string u = pq.top().second;
		pq.pop();

		vector<string> pos = position(u);
		for (string& v : pos) {
			if (dist.find(v) == dist.end() || dist[u] + 1 < dist[v]) {
				dist[v] = dist[u] + 1;
				pq.push({-dist[v], v});
			}
		}
	}

	return dist[b];
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);

	string a, b;
	while(cin >> a >> b) {
		string x = a, y = b;
		x[0] = a[0] - 'a' + 1;
		x[1] = a[1] - '0';
		y[0] = b[0] - 'a' + 1;
		y[1] = b[1] - '0';

		int ans = solve(x, y);
		cout << "To get from " << a << " to " << b << " takes " << ans << " knight moves.\n";
	}


	return 0;
}