namespace CoordCompression {
	template<typename T>
	inline void compress(vector<T>& v) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
	}

	template<typename T>
	inline size_t get_index(vector<T>& v, T const&& val) {
		return lower_bound(v.begin(), v.end(), val) - v.begin();
	}

	template<typename T>
	inline T get_original(vector<T>& v, size_t const& val) {
		return v[val];
	}
}