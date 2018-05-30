/* string, find, substring, npos */
if (str.find("+") != string::npos) ans++;

/* vector, erase, repeated, unique */
vec.erase( unique( vec.begin(), vec.end() ), vec.end() );

/* vector, bound, lower, iterator */
int closeabs(vector<int> const& vec, int que) {
	auto const it = lower_bound(vec.begin(), vec.end(), que);
	
	if (*it == que) return que;
	else if (it == vec.begin()) return *it;
	
	if ( abs(*(it-1) - que) <= abs(*it - que)) return *(it-1);
	return *it;
}

/* vector, lower bound, iterator */
pos = lower_bound(vec.begin(), vec.end(), num) - vec.begin();
//pos = position of element, usage like: vector[pos]

/* ceil, floor */
n += ceil((max-min)/2); //returns a int: 5,4 -> 6
n -= floor((max-min)/2); //5,4 -> 5

/* vector, erase */
s.erase(s.begin()+i);

/* bit, shift, number, binary */
int bitX = (x >> i) & 1;

/* */