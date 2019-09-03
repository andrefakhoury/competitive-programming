#include <stdio.h>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<string> possible(string& ini) {
	vector<string> ret;

	for (int i = 0; i < 4; i++) {
		string a1 = ini;
		a1[i] = (a1[i] - '0' + 1)%10 + '0';

		string a2 = ini;
		a2[i] = (a2[i] - '0' - 1 + 10)%10 + '0';

		ret.push_back(a1);
		ret.push_back(a2);
	}

	return ret;
}

int bfs(string& s, string& f, map<string, bool>& proh) {
	map<string, int> dist;
	dist[s] = 0;
	queue<string> q;
	q.push(s);

	while(q.size()) {
		string u = q.front();
		q.pop();

		if (u == f) return dist[u];

		vector<string> pos = possible(u);
		for (string v : pos) {
			if (dist.find(v) == dist.end() and proh[v] == false) {
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}

	return -1;
}

int main() {
	int t; scanf("%d", &t);
	while(t--) {
		string ini, fim;

		for (int i = 0; i < 4; i++) {
			int x; scanf("%d", &x);
			ini += to_string(x);
		}

		for (int i = 0; i < 4; i++) {
			int x; scanf("%d", &x);
			fim += to_string(x);
		}

		map<string, bool> proh;
		int n; scanf("%d", &n);
		while(n--) {
			string s;
			for (int i = 0; i < 4; i++) {
				int x; scanf("%d", &x);
				s += to_string(x);
			}
			proh[s] = true;
		}

		printf("%d\n", bfs(ini, fim, proh));
	}
}