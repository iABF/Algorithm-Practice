#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 10005
#define MAXM 1000005
#define MOD 1000000007
#define ll long long
using namespace std;

int t, n, a, b;

int gcd(int x, int y) {
    return x == 0 ? y : gcd(y % x, x);
}

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> a >> b;
        b /= gcd(a, b);
        for (int i = 2; i < n; ++i) {
            cin >> a;
            b /= gcd(a, b);
        }
        if (b == 1)cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}