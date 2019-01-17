#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl
#define pb push_back

using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	int n;
	string s, ans;
	map<string, int> twog;
	using pair_type = decltype(twog)::value_type;
	
	cin >> n >> s;
	
	for (int i = 0; i < n-1; i++) {
		int qt = 1;
		twog[s.substr(i, 2)]++;
	}
	
	auto pr = std::max_element
	(
	    begin(twog), end(twog),
	    [] (const pair_type & p1, const pair_type & p2) {
	        return p1.second < p2.second;
	    }
	);
	
	cout << pr->first << endl;
	
	
	
	return 0;
}
