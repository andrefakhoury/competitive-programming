#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
int a[MAXN];

int main() {
    int n, k, x, q; scanf("%d%d", &n, &k); q = k;
    
    for (int i = 0; i < n; i++) scanf("%d", a+i);
    sort(a, a + n);
    
    int carry = 0, i = 0;
    vector<int> ans;
    
    while(k--) {
        if (i >= n) break;
        
        a[i] -= carry;
        if (a[i] > 0) {
            ans.push_back(a[i]);
            carry += a[i];
        } else k++;
        
        i++;
    }
    
    for (int i = 0; i < q; i++) {
        if (i >= ans.size()) printf("0\n");
        else printf("%d\n", ans[i]);
    }
    
    return 0;
}