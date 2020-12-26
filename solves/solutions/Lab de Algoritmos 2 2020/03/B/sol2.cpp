#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

const char* desired = "123456789ABCDEF0";
const char* orderOfMovement = "ULRD";
const string IMPOSSIBLE = "This puzzle is not solvable.";

inline int get(int i, int j) {
  return i * 4 + j;
}

inline bool pos(string const& s, int direction, int p) {
  int i = p / 4;
  int j = p % 4;

  if (direction == 0) { // UP
    if (i == 0) return false;
  } else if (direction == 1) { // LEFT
    if (j == 0) return false;
  } else if (direction == 2) { // RIGHT
    if (j == 3) return false;
  } else { // DOWN
    if (i == 3) return false;
  }

  return true;
}

inline string nextState(string s, int direction, int p) {
  int i = p / 4;
  int j = p % 4;

  if (direction == 0) { // UP
    if (i == 0) return "";
    swap(s[p], s[get(i-1, j)]);
  } else if (direction == 1) { // LEFT
    if (j == 0) return "";
    swap(s[p], s[get(i, j-1)]);
  } else if (direction == 2) { // RIGHT
    if (j == 3) return "";
    swap(s[p], s[get(i, j+1)]);
  } else { // DOWN
    if (i == 3) return "";
    swap(s[p], s[get(i+1, j)]);
  }

  return s;
}

inline int manhDist(int p, int i, int j) {
  return abs(i - (p/4)) + abs(j - (p%4));
}

inline int getw(string const& s) {
  int ans = 0;
  for (int i = 0; i < (int) s.size(); i++)
    ans += manhDist(s[i] == '0' ? 15 : s[i] >= '1' && s[i] <= '9' ? s[i]-'1' : s[i]-'A'+9, i/4, i%4);
  return ans << 3;
}

inline int findx(string const& s) {
  for (int i = 0; i < (int) s.size(); i++) if (s[i] == '0')
    return i;
  return -1;
}

inline bool isSolvable(string const& s){
  int row = 4 - (findx(s) / 4);
  int inv = 0;
  
  for (int i = 0; i < (int) s.size(); i++) if (s[i] != '0') {
    for (int j = 0; j < i; j++) if (s[j] != '0') {
      inv += s[i] < s[j];
    }
  }

  if (row%2 == 0) return inv % 2;
  else return inv % 2 == 0;
}

inline string dijkstra(string const& s) {
  priority_queue<pair<int, string>> pq;
  map<string, string> dist;
  pq.emplace(-getw(s), s);
  dist[s] = "";

  while(pq.size()) {
    auto u = pq.top();
    pq.pop();
    if (u.se == desired) return dist[u.se];
    
    string& d = dist[u.se];
    int curSize = d.size();
    if (curSize > 45) continue;
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

  return IMPOSSIBLE;
}

inline void solve() {
  string s;
  for (char i = 0; i < 16; i++) {
    int x; cin >> x;
    s += x >= 10 ? x - 10 + 'A' : x + '0';
  }
  // cerr << s << endl;
  cout << (isSolvable(s) ? dijkstra(s).size() : -1) << "\n";
}

int main() {
  ios::sync_with_stdio(false); cin.tie(NULL);
  int T = 1;
  while(T--) {
    solve();
  }
}