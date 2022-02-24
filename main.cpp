#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 20005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

int n, ans = 0;
struct boat {
    int beg;
    int end;
} a[MAXN];

bool cmp(boat &x, boat &y) {
    if (x.beg == y.beg)return x.end < y.end;
    return x.beg < y.beg;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> a[i].beg >> a[i].end;
    sort(a, a + n, cmp);
    int l = a[0].beg, r = a[0].end;
    for (int i = 1; i < n; ++i) {
        if (a[i].beg <= r)r = max(a[i].end, r);
        else ans += r - l, l = a[i].beg, r = a[i].end;
    }
    cout << ans + r - l << endl;
}
