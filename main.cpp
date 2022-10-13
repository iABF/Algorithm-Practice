#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;


int n;
struct seg {
    int a, b;
} c[MAXN];

bool cmp(const seg &x, const seg &y) {
    if (x.b == y.b)return x.a < y.a;
    return x.b < y.b;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> c[i].a >> c[i].b;
    sort(c, c + n, cmp);
    int ans = 0, cur = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i].a >= cur) {
            cur = c[i].b;
            ans++;
        }
    }
    cout << ans << endl;
}
