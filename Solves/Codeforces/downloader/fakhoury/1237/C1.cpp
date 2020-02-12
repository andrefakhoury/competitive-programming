#include <bits/stdc++.h>
using namespace std;
 const int MAXN = 2e3 + 5;
const int INF = 0x3f3f3f3f;
 struct Point {
 int x, y, z;
 Point() {}
 Point(int a, int b, int c) {
  x = a, y = b, z = c;
 }
};
 Point a[MAXN];
vector<int> ptX[MAXN];
bool vis[MAXN];
 bool cmp(int i, int j) {
 return a[i].y == a[j].y ? a[i].z < a[j].z : a[i].y < a[j].y;
}
 bool inside(Point& a, Point& b, Point& c) {
 bool ret =  min(a.x, b.x) <= c.x;
 ret      &= max(a.x, b.x) >= c.x;
 ret      &= min(a.y, b.y) <= c.y;
 ret      &= max(a.y, b.y) >= c.y;
 ret      &= min(a.z, b.z) <= c.z;
 ret      &= max(a.z, b.z) >= c.z;
  return ret;
}
 int main() {
 ios::sync_with_stdio(false); cin.tie(NULL);
 int n; cin >> n;
  set<int> allX, allY, allZ;
 map<int, int> cmpX, cmpY, cmpZ;
  for (int i = 1; i <= n; i++) {
  cin >> a[i].x >> a[i].y >> a[i].z;
  allX.insert(a[i].x);
  allY.insert(a[i].y);
  allZ.insert(a[i].z);
 }
  /** Compression */
 int cntX = 0, cntY = 0, cntZ = 0;
 for (int i : allX) cmpX[i] = ++cntX;
 for (int i : allY) cmpY[i] = ++cntY;
 for (int i : allZ) cmpZ[i] = ++cntZ;
 for (int i = 1; i <= n; i++) {
  a[i].x = cmpX[a[i].x];
  a[i].y = cmpY[a[i].y];
  a[i].z = cmpZ[a[i].z];
  ptX[a[i].x].push_back(i);
 }
 /***************/
  for (int x = 1; x <= cntX; x++) sort(ptX[x].begin(), ptX[x].end(), cmp);
  vector<pair<int, int>> ans;
  set<int> notUsed;
 for (int i = 1; i <= n; i++) notUsed.insert(i);
  while(ans.size() < n/2) {
  int i;
  for (auto it = notUsed.begin(); it != notUsed.end(); it = notUsed.upper_bound(i)) {
   i = *it;
   if (vis[i]) continue;
    Point cur = Point(INF, INF, INF);
   int curAns = -1;
   for (int j : notUsed) {
    if (vis[j] || i == j) continue;
    if (curAns == -1 || inside(a[i], cur, a[j])) cur = a[j], curAns = j;
   }
    if (curAns == -1) continue;
   notUsed.erase(i); notUsed.erase(curAns);
   vis[i] = vis[curAns] = true;
   ans.emplace_back(i, curAns);
  }
 }
  for (auto p : ans)
  cout << p.first << ' ' << p.second << '\n';
}