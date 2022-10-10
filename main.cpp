#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

int n, m, a;
double ans = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        double sum = 0;
        int l = INF, r = -1;
        for (int j = 0; j < m; ++j) {
            cin >> a;
            if (a < l)l = a;
            if (a > r)r = a;
            sum += a;
        }
        sum = (sum - l - r) / (m - 2);
        if (sum > ans)ans = sum;
    }
    printf("%.2lf", ans);
}
