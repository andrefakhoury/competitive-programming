#include <bits/stdc++.h>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 0x3f3f3f3f;
const int MAXN = 4e4;
const double EPS = 1e-12;
 mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 inline double dist(double x, double y, double z) {
 return x * x + y * y + z * z;
}
 double x[MAXN], y[MAXN], z[MAXN];
int main() {
 int n; scanf("%d", &n);
  double X = 0, Y = 0, Z = 0;
 for (int i = 0; i < n; i++) {
  scanf("%lf%lf%lf", x+i, y+i, z+i);
  X += x[i], Y += y[i], Z += z[i];
 }
  for (int i = n; i < MAXN; i++)
  x[i] = x[0], y[i] = y[0], z[i] = z[0];
  X /= n, Y /= n, Z /= n;
  double d = 0, p = 0.1;
  while(p > EPS) {
  d = dist(x[0]-X, y[0]-Y, z[0]-Z);
  int j = 0;
   for (int i = 1; i < MAXN; i++) {
   double cur = dist(x[i]-X, y[i]-Y, z[i]-Z);
   if (d < cur) d = cur, j = i;
  }
  X += (x[j]-X) * p;
  Y += (y[j]-Y) * p;
  Z += (z[j]-Z) * p;
  p *= 0.998;
 }
  printf("%.10lf %.10lf %.10lf\n", X, Y, Z);
 return 0;
}