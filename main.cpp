#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 305
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int n;
ll h[MAXN] = {0}, ans;

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> h[i];
    sort(h + 1, h + n + 1);
    for (int i = 1; i < n - i; ++i)
        ans += (h[i] - h[n - i]) * (h[i] - h[n - i]) + (h[i] - h[n - i + 1]) * (h[i] - h[n - i + 1]);
    if (n % 2 == 0)ans += (h[n / 2] - h[n / 2 + 1]) * (h[n / 2] - h[n / 2 + 1]);
    ans += h[n] * h[n];
    cout << ans << endl;
}
