#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 5005
#define MOD 1000000007
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

ll n, a[MAXN] = {0}, c, mm = 0;
ll ans = 0;

ll C(ll m, ll k) {
    if (k == 2)return (m * (m - 1) / 2) % MOD;
    if (k == 3)return (m * (m - 1) * (m - 2) / 6) % MOD;
    return 0;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> c;
        a[c]++;
        mm = mm > c ? mm : c;
    }
    for (int i = 2; i <= mm; ++i) {
        if (a[i] >= 2) {
            if (a[i] >= 3 && a[0])ans = (ans + (C(a[i], 3) * a[0]) % MOD) % MOD;

            ll p = C(a[i], 2);
            for (int j = 1; j <= i / 2; ++j) {
                if (j == i - j) {
                    if (a[j] >= 2)
                        ans = (ans + (p * C(a[j], 2)) % MOD) % MOD;
                } else if (a[j] && a[i - j]) {
                    ll m = (a[j] * a[i - j]) % MOD;
                    ans = (ans + (p * m) % MOD) % MOD;
                }
            }
        }
    }
    cout << ans << endl;
}
