#include <bits/stdc++.h>
using namespace std;

#define debugg(a) cout << ":" << (#a) << " : " << (a) << endl;
#define mset(x, y) memset(x, y, sizeof x)
#define pb push_back
#define mp make_pair
//ios::sync_with_stdio(false);

#define inf 0x3f3f3f3f
#define MAXN 200010
typedef long long ll;
typedef pair<int, int> pii;

ll somaLR[MAXN], somaRL[MAXN];
ll vet[MAXN];
map<ll, int> occ;

int main () {
  int n; scanf("%d", &n);
  
  for (int i = 1; i <= n; i++)
    scanf("%llu", vet+i);

  for (int i = 1; i <= n; i++)
    somaLR[i] = somaLR[i-1] + vet[i];

  for (int i = n, j = 1; i > 0; i--, j++) {
    somaRL[j] = somaRL[j-1] + vet[i];
    occ[somaRL[j]] = max(i, occ[somaRL[j]]);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (occ[somaLR[i]] && occ[somaLR[i]] > i) ans = max(ans, somaLR[i]);
  }
  printf("%llu\n", ans);
}