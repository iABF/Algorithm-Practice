#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1505
#define MOD 1000000007
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

ll x, y, m, n, dp[25][25] = {0};

int main() {
    cin >> m >> n >> x >> y;
    for (int i = 0; i <= m; ++i)
        for (int j = 0; j <= n; ++j) {
            ll u = (i - x) * (i - x) + (j - y) * (j - y);
            if (u == 5 || u == 0) {
                dp[i][j] = 0;
                continue;
            }
            if (!i && !j)dp[i][j] = 1;
            else if (!i)dp[i][j] = dp[i][j - 1];
            else if (!j)dp[i][j] = dp[i - 1][j];
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    cout << dp[m][n] << endl;
}
