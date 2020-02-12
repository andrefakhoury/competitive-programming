#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
 #define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define mk make_pair
 typedef long long ll;
typedef pair<int, int> pii;
 const int INF = 4e6;
const double EPS = 1e-7;
 int main() {
 int n; scanf("%d", &n);
 if (n&1) return !printf("-1\n");
 for (int i = 1; i <= n; i += 2) {
  printf("%d %d ", i+1, i);
 }
  printf("\n");
 return 0;
}