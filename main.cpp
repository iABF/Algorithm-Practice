#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

string s[5][10] = {
        {"XXX", "..X", "XXX", "XXX", "X.X", "XXX", "XXX", "XXX", "XXX", "XXX"},
        {"X.X", "..X", "..X", "..X", "X.X", "X..", "X..", "..X", "X.X", "X.X"},
        {"X.X", "..X", "XXX", "XXX", "XXX", "XXX", "XXX", "..X", "XXX", "XXX"},
        {"X.X", "..X", "X..", "..X", "..X", "..X", "X.X", "..X", "X.X", "..X"},
        {"XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX", "..X", "XXX", "XXX"},
};

char c[105];
int n;

int main() {
    cin >> n;
    cin >> c;
    for (int j = 0; j < 5; ++j) {
        for (int i = 0; i < n - 1; ++i)cout << s[j][c[i] - '0'] + '.';
        cout << s[j][c[n - 1] - '0'] << endl;
    }
}
