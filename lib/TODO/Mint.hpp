template<typename T, const T MOD>
class Mint {
public:
	T val;

	Mint() : val{} {}
	Mint(T val) : val{val} {}

	Mint& operator+=(int rhs) {
		val += rhs;
		if (val >= MOD) val -= MOD;
		return *this;
	}
};