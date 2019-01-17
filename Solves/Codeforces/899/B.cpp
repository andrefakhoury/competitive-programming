#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define MAXN 100005

vector<int> days;
// 
int main() {
    int n, x; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        days.pb(x);
    }
    
    vector<int> pos;
    for (int i = 0; i < 30; i++) {
        pos.pb(31); 
        if (i%4 == 0) pos.pb(29); else pos.pb(28);
        pos.pb(31);
        pos.pb(30);
        pos.pb(31);
        pos.pb(30);
        pos.pb(31);
        pos.pb(31);
        pos.pb(30);
        pos.pb(31);
        pos.pb(30);
        pos.pb(31);
    }
    
    int flag = 0;
    for (int i = 0; i < 336; i++) {
        flag = 0;
        if (days[0] == pos[i]) {
            for (int j = 1; j < n; j++) {
                if (days[j] != pos[i+j]) {
                    flag = 1; 
                    break;
                }
            }
            if (!flag) return !printf("Yes\n");
        }
    }
    
    
    printf("No\n");
    return 0;
}