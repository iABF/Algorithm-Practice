#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 47000
#define MOD 1000000007
#define ll long long
using namespace std;

bool prime[MAXN] = {false};
int p[10000], n = 0, ans = 0;
ll l, r;
bool is_prime[1000005];

void find_prime(int range) {
    for (int i = 2; i <= range; ++i)prime[i] = true;
    for (int i = 2; i <= range; ++i)
        if (prime[i]) {
            p[n++] = i;
            for (int j = i * 2; j <= range; j += i)prime[j] = false;
        }
}

int main() {
    cin >> l >> r;
    find_prime(int(sqrt(r)));
    for (ll i = l == 1 ? 2 : l; i <= r; ++i)is_prime[i - l] = true;
    for (int i = 0; i < n; ++i) {
        for (ll j = (l - 1) / p[i] * p[i] + p[i]; j <= r; j += p[i])
            if (j != p[i])is_prime[j - l] = false;
    }
    for (ll i = l; i <= r; ++i)if (is_prime[i - l])ans++;
    cout << ans << endl;
}