#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10007
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int n, a;
ll ans = 0;


int main() {
    while (cin >> a) {
        ans += a;
        n++;
    }
    cout << ans * (1 << (n - 1)) << endl;
}
