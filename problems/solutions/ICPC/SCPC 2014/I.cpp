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

const int MAXN = 1e5 + 5, INF = 0x3f3f3f3f;

struct A {
    char c;
    int f;

    A() {}
    A(char a, int b) {
        c = a, f = b;
    }

    bool operator<(A& e) const {
        return f == e.f ? c > e.c : f > e.f;
    }
};

char lower(char a) {
    if (a >= 'a' && a <= 'z') return a;
    return a + 32;
}

char aux[MAXN];

int main() {
    // ios::sync_with_stdio(false); cin.tie(NULL);
    int t; scanf("%d", &t);
    for (int cs = 1; cs <= t; cs++) {
        map<char, int> f;

        while(scanf(" %[^\n\r]", aux), aux[0] != '*') {
            int n = strlen(aux);
            for (int i = 0; i < n; i++) {
                if (aux[i] == ' ') continue;

                f[lower(aux[i])]++;
            }
        }

        vector<A> freq;
        for (char c = 'a'; c <= 'z'; c++) {
            freq.push_back(A(c, f[c]));
        }

        sort(freq.begin(), freq.end());

        ll sum = 0;
        for (int i = 0; i < 5; i++) {
            if (freq[i].f == 0) continue;
            sum += freq[i].c - 'a';
        }

        printf("Case %d: %s\n", cs, sum > 62 ? "Effective" : "Ineffective");
    }

    return 0;
}