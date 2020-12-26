ostream& operator<<(ostream& out, __int128 x) {
	string s; bool sig = x < 0; x = x < 0 ? -x : x;
	while(x > 0) s += x % 10 + '0', x /= 10;
	if (sig) s += '-'; reverse(s.begin(), s.end());
	return out << s;
}