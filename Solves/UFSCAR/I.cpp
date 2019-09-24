#include <bits/stdc++.h>
using namespace std;
map<int, int> books;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    string s;
    while(cin >> s) {
        stack<char> st;

        bool ok = true;
        for (char c : s) {
            if (c == '(') st.push(c);
            if (c == ')') {
                if (st.size() && st.top() == '(') st.pop();
                else ok = false;
            }
            if (c == '{') st.push(c);
            if (c == '}') {
                if (st.size() && st.top() == '{') st.pop();
                else ok = false;
            }
            if (c == '[') st.push(c);
            if (c == ']') {
                if (st.size() && st.top() == '[') st.pop();
                else ok = false;
            }
        }

        ok &= st.empty();

        if (ok) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }
   
}