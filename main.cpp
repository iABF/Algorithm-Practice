#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 5005
#define MOD 1000000
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n-1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, m, p, x, y;
int s[MAXN];

int find(int r) {
    return r == s[r] ? r : s[r] = find(s[r]);
}


int main() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i)s[i] = i;
    while (m--) {
        cin >> x >> y;
        s[find(x)] = find(y);
    }
    while (p--) {
        cin >> x >> y;
        cout << (find(x) == find(y) ? "Yes" : "No") << endl;
    }
}
