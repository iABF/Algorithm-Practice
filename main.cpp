#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 10005
#define MOD 1000000007
#define ll long long
using namespace std;

ll a, b, ans = 0;

void solve(ll x, ll y) {
    if (!x)return;
    ans += y / x * x * 4;
    solve(y % x, x);
}

int main() {
    cin >> a >> b;
    if (a > b)swap(a, b);
    solve(a, b);
    cout << ans << endl;
}