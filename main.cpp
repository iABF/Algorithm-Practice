#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;


void gen(int k, int x_offset, int y_offset, int x, int y) {
    if (k == 2)cout << 3 - x + x_offset << ' ' << 3 - y + y_offset << ' ' << 2 * x + y - 2 << endl;
    else {
        int m = k / 2;
        int rx = (x - 1) / m, ry = (y - 1) / m;
        cout << 1 - rx + m + x_offset << ' ' << 1 - ry + m + y_offset << ' ' << 2 * rx + ry + 1 << endl;
        if (!rx && !ry)gen(m, x_offset, y_offset, x, y);
        else gen(m, x_offset, y_offset, m, m);
        if (!rx && ry)gen(m, x_offset, y_offset + m, x, y - m);
        else gen(m, x_offset, y_offset + m, m, 1);
        if (rx && !ry)gen(m, x_offset + m, y_offset, x - m, y);
        else gen(m, x_offset + m, y_offset, 1, m);
        if (rx && ry)gen(m, x_offset + m, y_offset + m, x - m, y - m);
        else gen(m, x_offset + m, y_offset + m, 1, 1);
    }
}

int main() {
    int k, x, y;
    cin >> k >> x >> y;
    gen(1 << k, 0, 0, x, y);
}
