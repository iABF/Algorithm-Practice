#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 50005
#define MOD 1000000007
#define ll long long
using namespace std;

int n, k;
int a[MAXN];
int dp[MAXN] = {0, 1};
int sp[MAXN] = {0, 1};

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 2; i <= n; ++i) {
        int *t = lower_bound(a + 1, a + i, a[i] - k);
        int index = t - a - 1;
        sp[i] = max(sp[i - 1], i - index);
        dp[i] = max(dp[i - 1], sp[index] + i - index);
    }
    cout << dp[n] << endl;
}