#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 2005
#define MOD 1000000007
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, m, k, t, C[MAXN][MAXN], col[MAXN];
ll cnt[MAXN][MAXN] = {0};

int main() {
    cin >> t >> k;
    for (int i = 0; i < MAXN; ++i)C[i][0] = 1, col[i] = 1;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i) {
            int right_edge = min(m, i);
            for (; col[i] <= right_edge; ++col[i]) {
                C[i][col[i]] = (C[i - 1][col[i]] + C[i - 1][col[i] - 1]) % k;
                cnt[i][col[i]] = cnt[i][col[i] - 1];
                if (!C[i][col[i]]) cnt[i][col[i]]++;
            }
        }
        ll ans = 0;
        for (int i = 0; i <= n; ++i)ans += cnt[i][min(m, i)];
        cout << ans << endl;
    }
}