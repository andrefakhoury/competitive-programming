namespace CoordCompress {
	template<typename T> inline void compress(vector<T>& v) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	template<typename T> inline size_t get_id(vector<T>& v, T const&& val) {
		return lower_bound(v.begin(), v.end(), val) - v.begin();
	}
}