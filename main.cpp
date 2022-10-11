#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1505
#define MOD 1000000007
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

unsigned ll n, dp[5005] = {1, 1};

int main() {
    cin >> n;
    for (int i = 2; i <= n; ++i)dp[i] = dp[i - 1] + dp[i - 2];
    cout << dp[n] << endl;
}
