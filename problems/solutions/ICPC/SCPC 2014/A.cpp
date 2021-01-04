#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define DEBUG 1
#define ll long long

typedef pair<int, int> pii;

const int MAXN = 1e5 + 5, N = 10, INF = 0x3f3f3f3f;

char lower(char a) {
    if (a >= 'a' && a <= 'z') return a;
    return a + 32;
}

char aux[MAXN];
pair<char, char> s1[N], s2[N];
int n1, n2, memo[2][(1 << 9) + 5][(1 << 9) + 5][10];

bool solve(int p, int m1, int m2, int l) {
    int& ret = memo[p][m1][m2][l];
    if (~ret) return ret;

    bool can = false;
    
    if (p == 1) {
        for (int i = 0; i < n1; i++) {
            if (m1 & (1 << i)) continue;
            if (l != -1 && s2[l].se != s1[i].fi) continue;

            bool cur = solve(0, m1 | (1 << i), m2, i);
            can |= !cur;
            if (can) break;
        }
    } else {
        for (int i = 0; i < n2; i++) {
            if (m2 & (1 << i)) continue;
            if (l != -1 && s1[l].se != s2[i].fi) continue;

            can |= !solve(1, m1, m2 | (1 << i), i);
            if (can) break;
        }
    }

    return (ret = can);
}

int main() {
    // ios::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        scanf("%d", &n1);
        for (int i = 0; i < n1; i++) {
            scanf(" %[^\n\r]", aux);
            int len = strlen(aux);

            s1[i].fi = aux[0];
            s1[i].se = aux[len-1];
        }

        scanf("%d", &n2);
        for (int i = 0; i < n2; i++) {
            scanf(" %[^\n\r]", aux);
            int len = strlen(aux);

            s2[i].fi = aux[0];
            s2[i].se = aux[len-1];
        }

        memset(memo, -1, sizeof memo);

        printf("Game %d: player%d\n", cs, 2 - solve(1, 0, 0, -1));        
    }

    return 0;
}