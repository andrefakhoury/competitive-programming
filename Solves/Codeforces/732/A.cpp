#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, r; cin >> k >> r;
    for (int qt = 1; qt <= 10; qt++) {
        int price = qt * k;
        if (price%10 == r || price%10 == 0) {
            cout << qt << endl;
            return 0;
        }
    }
}