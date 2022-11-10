#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 1000000007
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, k, row_cnt = 0, row[MAXN] = {0}, col[MAXN] = {0};
ll ans = 0;


int main() {
    cin >> n >> k;
    for (int i = 1; i <= k; ++i)cin >> row[i] >> col[i];
    sort(row + 1, row + 1 + k);
    sort(col + 1, col + 1 + k);
    for (int i = 1; i <= k; ++i)if (row[i] != row[i - 1])ans += n, row_cnt++;
    for (int i = 1; i <= k; ++i)if (col[i] != col[i - 1])ans += n - row_cnt;
    cout << ans << endl;
}