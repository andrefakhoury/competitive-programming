#include <bits/stdc++.h>
using namespace std;

int main() {
    int y, w; cin >> y >> w;
    int t = 7 - max(y, w);
    
    if (t == 1) cout << "1/6" << endl;
    if (t == 2) cout << "1/3" << endl;
    if (t == 3) cout << "1/2" << endl;
    if (t == 4) cout << "2/3" << endl;
    if (t == 5) cout << "5/6" << endl;
    if (t == 6) cout << "1/1" << endl;
}