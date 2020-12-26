#include <bits/stdc++.h>
using namespace std;

int ac;

inline void solve_() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) printf("%d ", i);
    ac = n * n;
    printf("%d\n", ac);
    printf("%d\n", n);
}

int main(int argc, char* argv[]) { // dont write ANYTHING under those lines!
    vector<string> in_files, out_files;
    for(auto& p: filesystem::directory_iterator(".")) {
        if (p.path().extension() == ".in") in_files.push_back(p.path());
        else if (p.path().extension() == ".out") out_files.push_back(p.path());
    }

    sort(in_files.begin(), in_files.end());
    sort(out_files.begin(), out_files.end());

    int ac = 0, wa = 0, unk = 0;

    cerr << fixed << setprecision(2);
    for (auto& s : in_files) {
        freopen(s.c_str(), "r", stdin);
        freopen("_.out", "w", stdout);

        cerr << "Running " << s << ": " << flush;
        clock_t ck_ini = clock();
        solve_();
        double elapsed = double(clock() - ck_ini) / CLOCKS_PER_SEC;
        fclose(stdout);

        ifstream cur("_.out");

        string my_out((istreambuf_iterator<char>(cur)), (istreambuf_iterator<char>()));

        s.pop_back(); s.pop_back(); s += "out";
        if (binary_search(out_files.begin(), out_files.end(), s)) {
            ifstream exp(s);
            string exp_out((istreambuf_iterator<char>(exp)), (istreambuf_iterator<char>()));

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

    ifstream src(string(argv[0]) + ".cpp");
    string src_content((istreambuf_iterator<char>(src)), (istreambuf_iterator<char>()));

    auto it_main = src_content.find("int main(int argc, char* argv[]) {");
    src_content.erase(it_main);
    src_content += "int main() {\n"
//                   "    freopen(\"a.in\", \"r\", stdin);\n"
//                   "    freopen(\"a.out\", \"r\", stdout);\n"
                   "    solve_();\n"
                   "}\n";

    ofstream dst("../../output/sol.cpp");
    dst << src_content;
}