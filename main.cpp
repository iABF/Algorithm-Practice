#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 55
#define MOD 1000000007
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, a[MAXN];
ll ans = 1;


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        if (a[i] - i <= 0) {
            cout << 0 << endl;
            return 0;
        }
        ans = (ans * (a[i] - i)) % MOD;
    }
    cout << ans << endl;
}