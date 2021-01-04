#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define eb emplace_back
#define mk make_pair
#define fi first
#define se second
#define mset(a, b) memset(a, b, sizeof(a))
using ll = long long;
using pii = pair<int, int>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<class Ty> Ty randint(Ty a, Ty b) { return uniform_int_distribution<Ty>(a, b)(rng); }

template<class T> void DBG(T&& x) { cerr << x << " "; }
template<class T, class...Args> void DBG(T&& x, Args&&... args) { DBG(x); DBG(args...); }
#define DBG(...) { cerr << "[" << #__VA_ARGS__ << "]: "; DBG(__VA_ARGS__); cerr << endl; }
template<class num> inline void rd(num& x) { cin >> x; }
template <class Ty, class... Args> inline void rd(Ty& x, Args&... args) { rd(x); rd(args...); }
template<class num> inline void print(num&& x) { cout << x; }
template <class Ty, class... Args> inline void print(Ty&& x, Args&&... args) { print(x); print(' '); print(args...); }
#define print(...) { print(__VA_ARGS__); print('\n'); }

struct Solver {
	const int MAXN = 2e5 + 5, INF = 0x3f3f3f3f;

	inline void run_test(int test_case) {

	}

	inline void prepare() { // first thing to run
		ios::sync_with_stdio(false); cin.tie(nullptr);
	}
};

/* **************************************************** */

// CHANGE HERE if there are multiple test cases
const enum TEST_TYPE { SINGLE, MULTIPLE, MULTIPLE_EOF } test_type = MULTIPLE;

inline void go_for_it() {
	if (test_type == SINGLE) {
		Solver solver;
		solver.prepare();
		solver.run_test(1);
	} else if (test_type == MULTIPLE) {
		Solver solver;
		solver.prepare();
		int test_count; rd(test_count);
		for (int test_number = 1; test_number <= test_count; test_number++)
			solver.run_test(test_number);
	} else {
		Solver solver;
		solver.prepare();
		for (int test_number = 1;; test_number++)
			solver.run_test(test_number);
	}
}

int main(int argc, char* argv[]) { // dont write ANYTHING under these lines!
	const bool RUN_FROM_STDIN = false; // change here if want to input manually to stdin

	if (argc == 1 && !RUN_FROM_STDIN) {
		vector<string> in_files, out_files;
		for(auto& p: filesystem::directory_iterator(".")) {
			if (p.path().extension() == ".in") in_files.push_back(p.path());
			else if (p.path().extension() == ".out") out_files.push_back(p.path());
		}

		sort(in_files.begin(), in_files.end());
		sort(out_files.begin(), out_files.end());

		int ac = 0, wa = 0, unk = 0;

		auto simplify = [](string& x) {
			while(!x.empty() && (x.back() == '\n' || x.back() == ' ')) x.pop_back();
			reverse(x.begin(), x.end());
			while(!x.empty() && (x.back() == '\n' || x.back() == ' ')) x.pop_back();
			reverse(x.begin(), x.end());
			for (size_t i = 0; i + 1 < x.size(); i++) {
				if (x[i] == ' ' && (x[i + 1] == ' ' || x[i + 1] == '\n')) {
					x.erase(i, 1);
					i--;
				}
			}
		};

		cerr << fixed << setprecision(2);
		for (auto& s : in_files) {
			freopen(s.c_str(), "r", stdin);
			freopen("_.out", "w", stdout);

			cerr << "Running " << s << ": " << flush;

			clock_t ck_ini = clock();
			go_for_it();
			double elapsed = double(clock() - ck_ini) / CLOCKS_PER_SEC;
			cout << flush;
			fclose(stdout);

			ifstream cur("_.out");

			string my_out((istreambuf_iterator<char>(cur)), (istreambuf_iterator<char>()));
			simplify(my_out);

			s.pop_back(); s.pop_back(); s += "out";
			if (binary_search(out_files.begin(), out_files.end(), s)) {
				ifstream exp(s);
				string exp_out((istreambuf_iterator<char>(exp)), (istreambuf_iterator<char>()));
				simplify(exp_out);

				if (my_out == exp_out) {
					ac++;
					cerr << "AC in " << elapsed << "s" << endl << flush;;
				} else {
					wa++;
					cerr << "WA in " << elapsed << "s" << endl << flush;;
					cerr << "====== Expected ======" << endl << exp_out << endl;
				}
			} else {
				unk++;
				cerr << "? in " << elapsed << " s" << endl << flush;;
			}
			cerr << "====== Produced ======" << endl << my_out << endl;
		}

		cerr << "==================\n";
		cerr << "Finished! " << ac << " AC, " << wa << " WA, " << unk << " UNKNOWN" << endl << flush;
	} else {
		go_for_it();
	}

	ifstream src(string(argv[0]) + ".cpp");
	string src_content((istreambuf_iterator<char>(src)), (istreambuf_iterator<char>()));

	auto it_main = src_content.find("int main(int argc, char* argv[]) {");
	src_content.erase(it_main);
	src_content +=
			"int main() {\n"
			//			"    freopen(\"a.in\", \"r\", stdin);\n"
			//			"    freopen(\"a.out\", \"r\", stdout);\n"
			"    go_for_it();\n"
			"}\n";

	ofstream dst("../../output/sol.cpp");
	dst << src_content;
}