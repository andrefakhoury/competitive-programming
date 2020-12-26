#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define fastcin ios::sync_with_stdio(false); cin.tie(0);

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 0x3f3f3f3f;
const int MAXN = 2e5 + 5;

struct City {
    int p, x, id;

    City() {}

    void read(int i) {
        cin >> x >> p;
        id = i;
    }

    bool const operator<(const City& b) const{
        return (this->x == b.x) ? (this->p < b.p) : (this->x < b.x);
    }
};

struct cmp {
    bool operator() (const City& a, const City& b) const {
        return (a.p == b.p) ? (a.x < b.x) : (a.p < b.p);
    }
};

bool cmpPop(City& a, City& b) {
    return (a.p == b.p) ? (a.x < b.x) : (a.p < b.p);
}

set<City> st;
map<int, set<City, cmp> > mp;

int main(){
    fastcin;

    int n; cin >> n;
    vector<City> a(n);


    vector<int> ans(n, -1);

    for (int i = 0; i < n; i++) {
        a[i].read(i);
        st.insert(a[i]);
        mp[a[i].x].insert(a[i]);
    }

    sort(a.begin(), a.end(), cmpPop);

    for (City c : a) {
        auto it = st.find(c);


        auto i1 = it;
        auto i2 = it;

        int dist = INT_MAX, pop = -1;

        if (it != st.begin()) {
            
            i2--;

            dist = abs((*i2).x - (*it).x);
            ans[c.id] = (*(mp[(*i2).x].rbegin())).id + 1;
            pop = (*(mp[(*i2).x].rbegin())).p;
        }

        i1++;
        if (i1 != st.end()) {
            if (dist > abs((*i1).x - (*it).x)) {
                ans[c.id] = (*(mp[(*i1).x].rbegin())).id + 1;
            } else if (dist == abs((*i1).x - (*it).x)) {
                if (pop < (*(mp[(*i1).x].rbegin())).p)
                    ans[c.id] = (*(mp[(*i1).x].rbegin())).id + 1;
            }
        }

        st.erase(it);
        mp[c.x].erase(c);
    }

    for (int i : ans) cout << i << ' ';
    cout << endl;

    return 0;
}