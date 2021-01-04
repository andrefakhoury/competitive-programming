#include <iostream>
using namespace std;

int main() {
    int n, r, x; cin >> n >> r;
    while(n--) {
        cin >> x;
        if (x >= r) cout << "Good boi\n";
        else cout << "Bad boi\n";
    }
    return 0;
}