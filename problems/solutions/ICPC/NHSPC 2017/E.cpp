#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;

int a[MAXN], freq[MAXN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int t; cin >> t;
    while(t--) {
        memset(a, 0, sizeof a);
        memset(freq, 0, sizeof freq);

        int n; cin >> n;
        long long sum = 0;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            freq[a[i]]++;

            if (freq[a[i]]> 1) sum = 1;
        }


        for (int i = 1; i <= n; i++) {
            freq[a[i]]--;
            sum += n - i - freq[a[i]];
        }

        cout << sum << '\n';
    }
}