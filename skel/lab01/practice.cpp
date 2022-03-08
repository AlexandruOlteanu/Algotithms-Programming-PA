#include<bits/stdc++.h>
using namespace std;

int matrix[1000][1000];
int neutilizat = 1;

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


int main() {

    int n;
    cin >> n;
    n = (1 << n);
    rezolvare(1, 1, n, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << '\n';
    }



    return 0;
}