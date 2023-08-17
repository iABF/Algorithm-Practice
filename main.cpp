#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 1000000007
#define ll long long

using namespace std;

int n, k;
int a[MAXN];
int f[MAXN][MAXN] = {0}, g[MAXN][MAXN] = {0};

int dpf(int x, int y) {
    if (y >= 0)return f[x][y];
    else return 0;
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            f[i][j] = max(g[i - 1][j], dpf(i - 1, j - 1)) + a[i];
            g[i][j] = max(f[i - 1][j], g[i - 1][j]);
        }
    }
    cout << max(f[n][k], g[n][k]) << endl;
}


// 2023-8-17 21:16:40
// 2023-8-17 21:52:58