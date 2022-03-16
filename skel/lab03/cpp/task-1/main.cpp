#include <bits/stdc++.h>
using namespace std;

const int inf = 2e9;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, S;
    vector<int> v;

    void read_input() {
        ifstream fin("in");
        fin >> n >> S;
        for (int i = 1, e; i <= n; i++) {
            fin >> e;
            v.push_back(e);
        }
        fin.close();
    }

    int get_result() {
        vector<int> dp(S + 1, inf);
        dp[0] = 0;
        for (int i = 1; i <= S; ++i) {
            for (auto u : v) {
                if (u <= i) {
                    if (dp[i - u] != inf) {
                        dp[i] = min(dp[i], dp[i - u] + 1);
                    }
                }
            }
        }
        if (dp[S] == inf) dp[S] = -1;
        return dp[S];
    }

    void print_output(int result) {
        ofstream fout("out");
        fout << result;
        fout.close();
    }
};

// [ATENTIE] NU modifica functia main!
int main() {
    // * se aloca un obiect Task pe heap
    // (se presupune ca e prea mare pentru a fi alocat pe stiva)
    // * se apeleaza metoda solve()
    // (citire, rezolvare, printare)
    // * se distruge obiectul si se elibereaza memoria
    auto* task = new (nothrow) Task(); // hint: cppreference/nothrow
    if (!task) {
        cerr << "new failed: WTF are you doing? Throw your PC!\n";
        return -1;
    }
    task->solve();
    delete task;
    return 0;
}
