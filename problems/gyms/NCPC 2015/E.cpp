#include <bits/stdc++.h>

#define eb emplace_back
#define fi first
#define se second
#define mid ((l + r)/2)
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;

const int N = 201007;
int seg[4 * N]; // seg de maximo
int lazy[4 * N];

void prop(int p, int l, int r) {
    seg[p] += lazy[p];
    if(l != r) {
        lazy[2 * p] += lazy[p];
        lazy[2 * p + 1] += lazy[p];
    }
    lazy[p] = 0;
}

int query(int p, int l, int r, int a, int b) {
    prop(p, l, r);
    if(r < a or l > b) return 0;
    if(l >= a and r <= b) {
        return seg[p];
    }
    return max(query(2 * p, l, mid, a, b), query(2 * p + 1, mid+1, r, a, b));
}

void update(int p, int l, int r, int a, int b) {
    prop(p, l, r);
    if(r < a or l > b) return;

    if(l >= a and r <= b) {
        lazy[p]++;
        prop(p, l, r);
    } else {
        update(2 * p, l, mid, a, b);
        update(2 * p + 1, mid+1, r, a, b);
        seg[p] = max(seg[2 * p], seg[2 * p + 1]);
    }
}

int main() {
    int n, k; cin >> n >> k;

    vector<ii> segments;
    vector<int> X;
    for(int i = 1; i <= n; ++i) {
        int l, r; cin >> l >> r;
        X.eb(l);
        X.eb(r);
        segments.eb(r, l);
    }

    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    int m = X.size();

    sort(segments.begin(), segments.end());

    int tot = 0;
    for(int i = 0; i < segments.size(); ++i) {
        // se da pra pegar pega;
        int l, r;
        tie(r, l) = segments[i];

        l = lower_bound(X.begin(), X.end(), l) - X.begin();
        r = lower_bound(X.begin(), X.end(), r) - X.begin();


        if(query(1, 0, m-1, l, r-1) < k) {
            tot++;
            update(1, 0, m-1, l, r-1);
        }
    }

    cout << tot << endl;
}