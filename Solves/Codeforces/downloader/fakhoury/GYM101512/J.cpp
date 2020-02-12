#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
#define fastcin ios_base::sync_with_stdio(false);cin.tie(NULL);
 #define endl "\n"
#define MAX
 using ll = long long;
 int const maxn = 250;
 char v[maxn][maxn];
 int main()
{ 
 fastcin;
  int t;
 cin >> t;
  cout << t << "\n";
  while (t--) {
  memset(v, '#', sizeof(v));
   int x = maxn/2, y = maxn/2;
  int xmin = x, xmax = x, ymin = y, ymax = y;
  int dir = 0;
    v[x][y] = '.';
   string s;
  cin >> s;
   for (char c : s) {
   if (c == 'B') {
    dir = (dir + 2) % 4;
   }
   else if (c == 'L') {
    dir = (dir + 1) % 4;
   }
   else if (c == 'R') {
    dir = (dir+3)%4;
   }
    switch(dir) {
    case 0:
     y++;
     break;
    case 1:
     x--;
     break;
    case 2:
     y--;
     break;
    case 3:
     x++;
     break;
   }
    v[x][y] = '.';
   xmin = min(xmin, x);
   xmax = max(xmax, x);
   ymin = min(ymin, y);
   ymax = max(ymax, y);
  }
  cout << xmax-xmin+3 << " " << ymax-ymin+2 << "\n";
  for (int i = xmin-1; i <= xmax+1; i++) {
   for (int j = ymin; j <= ymax+1; j++) {
    cout << v[i][j];
   }
   cout << "\n";
  }
 }
}