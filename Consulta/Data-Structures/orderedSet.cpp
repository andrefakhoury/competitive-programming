#include <bits/stdc++.h>
using namespace std;

//C++11
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename tA, typename tB=null_type> using ord_set = tree<tA, tB, less<tA>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
	// performs all the operations as the basic set, but with two more operations
	ord_set<int> s;

	s.insert(1); // {1}
	s.insert(3); // {1, 3}
	s.insert(5); // {1, 3, 5}

	s.erase(3);  // {1, 5}

	int cnt = s.order_of_key(5); //qtt of strictly smaller than 5, O(logN)
	//cnt = 1
	
	int val = *s.find_by_order(1); //k-th elementh couting from 0, in O(logN)
	//val = 5
}