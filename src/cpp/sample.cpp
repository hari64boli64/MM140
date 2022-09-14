#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, JC, FC;
    cin >> N >> JC >> FC;

    int numPainted = 0;
    bool grid[N][N];
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++) {
            char a;
            cin >> a;
            if (a == '#') {
                grid[r][c] = true;
                numPainted++;
            } else
                grid[r][c] = false;
        }

    bool first = true;
    int curR = 0;
    int curC = 0;

    cout << (numPainted + 1) << endl;
    for (int r = 0; r < N; r++)
        for (int c = 0; c < N; c++)
            if (grid[r][c]) {
                cout << "J " << (r - curR + N) % N << " " << (c - curC + N) % N
                     << endl;
                if (first) cout << "D\n";
                first = false;
                curR = r;
                curC = c;
            }

    cout.flush();
    return 0;
}