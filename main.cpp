#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

bool c[1025][1025] = {false};
int n;

int main() {
    cin >> n;
    n = 1 << n;
    c[1][n - 1] = true;
    for (int j = 0; j < n - 1; ++j) cout << c[1][j] << ' ';
    cout << c[1][n - 1] << endl;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << (c[i][j] = c[i - 1][j] ^ c[i - 1][j + 1]);
            if (j == n - 1)cout << endl;
            else cout << ' ';
        }
    }
}
