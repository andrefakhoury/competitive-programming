#include <string>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

#define mp make_pair
typedef pair<int, int> pii;

string final = "123456789ABCDEF0";
pii manh[50];

char crt(int c) {
	if (c < 10) return c + '0';
	return c - 10 + 'A';
}

int h(string& s) {
	int ret = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		ret += abs(manh[s[i]-'0'].first - i/4) + abs(manh[s[i]-'0'].second - i%4);
	}
	return 5 * ret / 3;
}

int get(string& s) {
	for (int i = 0; i < (int)s.size(); i++) if (s[i] == '0') return i;
	return 0;
}

string solve(string& s) {
	unordered_map<string, string> dist;
	dist[s] = "";
	priority_queue<pair<int, string> > pq;
	pq.push(mp(0, s));

	while(pq.size()) {
		string u = pq.top().second;
		if (u == final) return dist[u];
		pq.pop();

		if (dist[u].size() > 50) continue;
		
		string v = u;
		int i = get(u);

		if (i != 0 && i != 4 && i != 8 && i != 12) {
			swap(v[i], v[i-1]);

			if (dist.find(v) == dist.end() || dist[u].size()+1 < dist[v].size()) {
				dist[v] = dist[u] + 'L';
				int w = dist[v].size() + h(u);
				pq.push(mp(-w, v));
			}

			swap(v[i], v[i-1]);
		}

		if (i != 3 && i != 7 && i != 11 && i != 15) {
			swap(v[i], v[i+1]);

			if (dist.find(v) == dist.end() || dist[u].size()+1 < dist[v].size()) {
				dist[v] = dist[u] + 'R';
				int w = dist[v].size() + h(u);
				pq.push(mp(-w, v));
			}

			swap(v[i], v[i+1]);
		}

		if (i >= 4) {
			swap(v[i], v[i-4]);

			if (dist.find(v) == dist.end() || dist[u].size()+1 < dist[v].size()) {
				dist[v] = dist[u] + 'U';
				int w = dist[v].size() + h(u);
				pq.push(mp(-w, v));
			}

			swap(v[i], v[i-4]);
		}

		if (i <= 11) {
			swap(v[i], v[i+4]);

			if (dist.find(v) == dist.end() || dist[u].size()+1 < dist[v].size()) {
				dist[v] = dist[u] + 'D';
				int w = dist[v].size() + h(u);
				pq.push(mp(-w, v));
			}

			swap(v[i], v[i+4]);
		}
	}

	return "This puzzle is not solvable.";
}

bool isPossible(string& s) {
	int inv = 0;
	for (int i = 0; i < (int)s.size(); i++)
		for (int j = i+1; j < (int)s.size(); j++) {
			if (s[i] == '0' || s[j] == '0') continue;
			inv += s[i] > s[j];
		}

	int row = 3 - (get(s)/4);

	if (row%2 == 0) return inv%2 == 0;
	else return inv%2 != 0;
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	for (int i = 0; i < (int)final.size(); i++)
		manh[final[i]-'0'] = mp(i/4, i%4);

	int t; cin >> t;

	while(t--) {
		string s;
		for (int i = 0; i <= 15; i++) {
			int c; cin >> c;
			s += crt(c);
		}
		if (isPossible(s)) 
			cout << solve(s) << "\n";
		else cout << "This puzzle is not solvable.\n";
	}

}