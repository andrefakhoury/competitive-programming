#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const char* desired = "123456789";
const char* orderOfMovement = "ulrd";

inline int get(int i, int j) {
	return i * 3 + j;
}

inline bool pos(string const& s, int direction, int p) {
	int i = p / 3;
	int j = p % 3;

	if (direction == 0) { // UP
		if (i == 0) return false;
	} else if (direction == 1) { // LEFT
		if (j == 0) return false;
	} else if (direction == 2) { // RIGHT
		if (j == 2) return false;
	} else { // DOWN
		if (i == 2) return false;
	}

	return true;
}

inline string nextState(string s, int direction, int p) {
	int i = p / 3;
	int j = p % 3;

	if (direction == 0) { // UP
		if (i == 0) return "";
		swap(s[p], s[get(i-1, j)]);
	} else if (direction == 1) { // LEFT
		if (j == 0) return "";
		swap(s[p], s[get(i, j-1)]);
	} else if (direction == 2) { // RIGHT
		if (j == 2) return "";
		swap(s[p], s[get(i, j+1)]);
	} else { // DOWN
		if (i == 2) return "";
		swap(s[p], s[get(i+1, j)]);
	}

	return s;
}

inline int manhDist(int p, int i, int j) {
	return abs(i - (p/3)) + abs(j - (p%3));
}

inline int getw(string const& s) {
	int ans = 0;
	for (int i = 0; i < (int) s.size(); i++)
		ans += manhDist(s[i]-'1', i/3, i%3);
	return ans << 3;
}

inline int findx(string const& s) {
	for (int i = 0; i < (int) s.size(); i++) if (s[i] == '9')
		return i;
	return -1;
}

bool isSolvable(string const& s){
	int inv = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		for (int j = i+1; j < (int)s.size(); j++) {
			if (s[i] == '9' || s[j] == '9') continue;
			inv += s[i] > s[j];
		}
	}
	return inv % 2 == 0;
}

inline string dijkstra(string const& s) {
	priority_queue<pair<int, string>> pq;
	map<string, string> dist;
	pq.emplace(-getw(s), s);
	dist[s] = "";

	int countDijk = 1e5;
	while(pq.size() && countDijk--) {
		auto u = pq.top();
		pq.pop();
		if (u.se == desired) return dist[u.se];
		
		string& d = dist[u.se];
		int curSize = d.size();
		int index = findx(u.se);
		if (-u.fi != curSize + getw(u.se)) continue;

		for (int i = 0; i < 4; i++) {
			if (!pos(u.second, i, index)) continue;
			string nx = nextState(u.second, i, index);
			if (dist.find(nx) == dist.end() or (int) dist[nx].size() > curSize + 1) {
				int w = curSize + 1 + getw(nx);
				pq.emplace(-w, nx);
				dist[nx] = d + orderOfMovement[i];
			}
		}
	}

	return "unsolvable";
}

inline void solve() {
	string s;
	for (char i = 0, c; i < 9; i++)
		cin >> c, s += (c == 'x' ? '9' : c);
	cout << (isSolvable(s) ? dijkstra(s) : "unsolvable") << "\n";
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL);
	int T; cin >> T;
	while(T--) {
		solve();
		if (T) cout << "\n";
	}
}