#include <bits/stdc++.h>
using namespace std;

class Task {
public:
    void solve() {
        read_input();
        print_output(get_result());
    }

private:
    int n, x, y;
    int matrix[1000][1000], neutilizat = 1;
    
    void read_input() {
        ifstream fin("in");
        fin >> n >> x >> y;
        fin.close();
    }

    int get_value(int n, int x, int y) {
        return matrix[x][y];
    }

    void rezolvare(int x1, int y1, int x2, int y2) {
        if (x1 == x2 && y1 == y2) {
            matrix[x1][y1] = neutilizat;
            ++neutilizat;
            return;
        }
        rezolvare(x1, y1, x1 + (x2 - x1) / 2, y1 + (y2 - y1) / 2);
        rezolvare(x1, y1 + (y2 - y1 + 1) / 2, x1 + (x2 - x1) / 2, y2);
        rezolvare(x1 + (x2 - x1 + 1) / 2, y1, x2, y1 + (y2 - y1) / 2);
        rezolvare(x1 + (x2 - x1 + 1) / 2, y1 + (y2 - y1 + 1) / 2, x2, y2);
    }

    int get_result() {
        rezolvare(1, 1, (1 << n), (1 << n));
        return get_value(n, x, y);
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
