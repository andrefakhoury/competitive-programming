#include <bits/stdc++.h>

using namespace std;
using lint = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int curr = 0;
    map<int, int> hist = {{0, 0}};
    for (int i = 1; i <= n; i++) {
        char c;
        int k;
        cin >> c;

        if (c == '+') {
            curr++;
        } else if (c == '-') {
            curr--;
        } else {
            cin >> k;
            curr = hist[i - k - 1];
        }
        hist[i] = curr;
    }
    cout << curr << endl;
}