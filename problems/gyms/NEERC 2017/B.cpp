#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

seed_seq seq {
    (uint64_t) chrono::duration_cast<chrono::nanoseconds>(
    	chrono::high_resolution_clock::now().
    	time_since_epoch()).count(),
    (uint64_t) __builtin_ia32_rdtsc(),
    (uint64_t) random_device{}(),
    (uint64_t) 17
};

mt19937 rd{seq};

bool iso1(int a, int b, int c, int h, int w) {
    return 2*a + 2*b <= h and 2*a + c <= w;
}

auto iso2 = iso1;

bool iso3(int a, int b, int c, int h, int w) {
    return a + b + c <= h and 2*a + 2*b <= w;
}

auto iso4 = iso1;

auto iso5 = iso3;

auto iso6 = iso3;

bool iso7(int a, int b, int c, int h, int w) {
    return 2*a + b <= h and 2*c + a + b <= w;
}

bool iso8(int a, int b, int c, int h, int w) {
    return a + b + c <= h and a + 2*b + c <= w;
}

bool iso9(int a, int b, int c, int h, int w) {
    return a + b <= h and a + b + 3*c <= w;
}

bool iso10(int a, int b, int c, int h, int w) {
    return a + b + c <= h and 2*a + b + c <= w;
}

auto iso11 = iso7;

auto tests = {iso1, iso2, iso3, iso4, iso5, iso6, iso7, iso8, iso9, iso10, iso11};

template<typename... Args>
bool test1(Args... args) {
    for (auto&& f : tests) {
        if (f(args...)) return true;
    }
    return false;
}

bool test(int a, int b, int c, int h, int w) {
    vector<int> v = {a, b, c};

    sort(v.begin(), v.end());

    do {
        if (test1(v[0], v[1], v[2], h, w)) {
            return true;
        }
    } while (next_permutation(v.begin(), v.end()));

    sort(v.begin(), v.end());

    do {
        if (test1(v[0], v[1], v[2], w, h)) {
            return true;
        }
    } while (next_permutation(v.begin(), v.end()));

    return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;

    int h, w;
    cin >> h >> w;

    if (test(a, b, c, h, w)) {
        cout << "Yes\n";
    }
    else cout << "No\n";
}
