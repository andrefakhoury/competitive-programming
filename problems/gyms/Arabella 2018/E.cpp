#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

using ll = long long;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> can_see(n);
        fill(can_see.begin(), can_see.begin() + k, 1);

        vector<int> small;
        for (int i = 0; i < n; i++) {
            char x;
            cin >> x;

            if (i < k or x == 'S') small.push_back(i);
        }

        auto last_see = small.begin()+k;

        int ans = 0;
        while (m--) {
            char op;
            cin >> op;

            if (op == 'A') {
                for (; last_see != small.end(); ++last_see) {
                    can_see[*last_see] = 1;
                }
            }
            else {
                int fail;
                cin >> fail;

                fail--;

                auto it = upper_bound(small.begin(), small.end(), fail);

                if (it == small.begin()) {
                    ans++;
                }
                else {
                    --it;

                    if (can_see[fail]) ans++;

                    for (; last_see <= it; ++last_see) {
                        can_see[*last_see] = 1;
                    }
                }                
            }
        }

        cout << ans << "\n";
    }
}