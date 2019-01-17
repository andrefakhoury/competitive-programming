#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mp make_pair

#define MAXN 300015

typedef pair<int, int> pii;
typedef pair<pii, int> piii;

vector<piii> v;

bool compare_this(const piii& a, const piii& b) {
    if(a.first.first != b.first.first) return a.first.first < b.first.first;
	return a.first.second > b.first.second;
}

int main() {
    int n, l, r; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &l, &r);
        v.pb(mp(mp(l, r), i));
    }
    
    sort(v.begin(), v.end(), compare_this);
    
    int maxR = v[0].first.second, id = v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first.second <= maxR) return !printf("%d %d\n", v[i].second, id);
        else {
            maxR = v[i].first.second;
            id   = v[i].second;
        }
    }
    printf("-1 -1\n");
    return 0;
}