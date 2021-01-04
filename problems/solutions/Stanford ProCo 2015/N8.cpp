#include <bits/stdc++.h>

using namespace std;
using lint = long long;
using gset = set<int, greater<int>>;

const int N = 1000 + 3;

int n;
vector<int> deck;
gset cards[N];

void solve(int i) {
    if (i >= n || !cards[i].empty()) return;
    bool can_2 = i != n - 3 && i != n - 1;
    bool can_3 = i <= n - 3;
    if (can_2) {
        solve(i + 2);
    }
    if (can_3) {
        solve(i + 3);
    }
    if (can_2) {
        gset aux = cards[i + 2];
        aux.insert(max(deck[i], deck[i + 1]));
        cards[i] = max(cards[i], aux);
    }
    if (can_3) {
        gset aux = cards[i + 3];
        aux.insert(max({deck[i], deck[i + 1], deck[i + 2]}));
        cards[i] = max(cards[i], aux);
    }
    /*cout << i << ": ";
    for (int c : cards[i]) {
        cout << c << " ";
    }
    cout << "\n";*/
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    deck.resize(n);
    for (int &c : deck) {
        cin >> c;
    }
    solve(0);
    gset ans = *max_element(cards, cards + n);
    stack<int> aux;
    for (int c : ans) {
        cout << c << "\n";
    }
}