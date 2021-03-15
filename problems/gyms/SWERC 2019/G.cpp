#include <bits/stdc++.h>

#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,sse4,avx,avx2")

using namespace std;

using ll = long long;

int const maxs = 202;

using Mask = bitset<maxs>;

struct Seg {
    struct Node {
        Mask b;

        static Node join(Node const& lhs, Node const& rhs) {
            Node ans = Node{lhs.b | rhs.b};
            return ans;
        }
    };

    int n;
    vector<Node> tree;

    Seg(vector<int> const& v) : n(v.size()), tree(n*3) {
        for (int i = 0; i < this->n; i++) update(i+1, v[i], true);
    }
    
    inline Mask query(int l, int r) {
        Mask ans{};
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) ans |= (tree[l++].b);
            if(r&1) ans |= (tree[--r].b);
        }
        return ans;
    }

    inline void update(int p, int val, bool v) {
        for(tree[p += n].b[val] = v; p > 1; p >>= 1) {
            tree[p >> 1].b = tree[p].b | tree[p^1].b;
        }
    }

    inline Mask get(int a, int b) {
        return query(a+1, b+1);
    }

    inline void clear(int pos, int val) {
        update(pos+1, val, false);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    
    int s, l, n;
    cin >> s >> l >> n;

    vector<string> animals(s);    
    for (auto& i : animals) cin >> i;

    sort(animals.begin(), animals.end());

    auto id = [&] (string const& s) {
        return lower_bound(animals.begin(), animals.end(), s) - animals.begin();
    };

    vector<Mask> not_friends(s);
    for (int i = 0; i < s; i++) {
        not_friends[i][i] = true;
    }

    for (int i = 0; i < l; i++) {
        string a, b;
        cin >> a >> b;

        int x = id(a), y = id(b);

        not_friends[x][y] = not_friends[y][x] = true;
    }

    for (int i = 0; i < s; i++) {
        not_friends[i].flip();
    }

    vector<int> v(n);
    vector<vector<int>> prox(s);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        v[i] = id(s);
        prox[v[i]].push_back(i);
    }

    for (auto& i : prox) reverse(i.begin(), i.end());

    Seg seg(v);

    vector<int> res;

    for (int i = 0; i < n; i++) {
        for (int at = 0; at < s; at++) {
            if (prox[at].empty()) continue;

            int pos = prox[at].back();

            Mask mask = seg.get(0, pos+1);

            if ((mask & not_friends[at]).none()) {
                res.push_back(at);
                prox[at].pop_back();
                seg.clear(pos, at);
                break;
            }
        }
    }

    for (auto i : res) {
        cout << animals[i] << ' ';
    }
    cout << "\n";
}  