#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int n, a[MAXN], ans;

int main() {
    cin >> n >> a[0];
    ans = a[0];
    for (int i = 1; i < n; ++i) {
        cin >> a[i];
        if (a[i] > a[i - 1])ans += a[i] - a[i - 1];
    }
    cout << ans << endl;
}
