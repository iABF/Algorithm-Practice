#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;


int n;
double t;
struct coin {
    double m;
    double v;
} c[105];

bool cmp(const coin &x, const coin &y) {
    return x.v / x.m > y.v / y.m;
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i)cin >> c[i].m >> c[i].v;
    sort(c, c + n, cmp);
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        if (c[i].m <= t) {
            t -= c[i].m;
            ans += c[i].v;
        } else {
            ans += c[i].v * t / c[i].m;
            break;
        }
    }
    printf("%.2lf\n", ans);
}
