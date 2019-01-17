#include <bits/stdc++.h>

using namespace std;

map<int, int> pos;

int main() {
    int q; scanf("%d ", &q);
    
    int ue, ud, id;
    char c;
    
    scanf("%c %d ", &c, &id);
    pos[id] = ue = ud = 0;
    
    while(--q) {
        scanf("%c %d ", &c, &id);
        
        if (c == "L") {
            pos[id] = --ue;
        } else if (c == "R") {
            pos[id] = ++ud;
        } else if (c == "?") {
            printf("%d\n", min(abs(ue-pos[id]), abs(pos[id]-ud)));
        } else {
            assert(0);
        }
        
        
    }
}