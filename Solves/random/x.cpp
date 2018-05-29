#include <bits/stdc++.h>
#define debugg(x) cout << ">>" << (#x) << " :: " << (x) << endl

using namespace std;

int closeabs(vector<int> const& vec, int que) {
	auto const it = lower_bound(vec.begin(), vec.end(), que);
	
	if (*it == que) return que;
	else if (it == vec.begin()) return *it;
	
	if ( abs(*(it-1) - que) <= abs(*it - que)) return *(it-1);
	return *it;
}

int main(void) {
	ios :: sync_with_stdio(false);
	
	int N, M, x;
	vector<int> vec;
	vector<int> queries;
	
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		cin >> x;
		vec.push_back(x);
	}
	
	vec.erase( unique( vec.begin(), vec.end() ), vec.end() );
	
	for (int i = 0; i < M; i++) {
		cin >> x;
		queries.push_back(closeabs(vec, x));
	}
	
	for (int i = 0; i < M; i++) {
		cout << queries[i] << "\n";
	}
	
	
	return 0;
}