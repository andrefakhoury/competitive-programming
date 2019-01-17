#include <iostream>
using namespace std;

int main() {
    int n, x, k = 0, ans = 0; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x == -1) {
            if (k >= 1) {
                k--;
            } else ans++;
        } else k += x;
    }
    
    cout << ans << endl;
}