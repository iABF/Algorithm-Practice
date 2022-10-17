#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int n;
int a[MAXN], m, ma = 0;

int find(int x, int l, int r) {
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        ll height = 0;
        for (int i = n - 1; i + 1; --i) {
            if (a[i] <= mid)break;
            height += a[i] - mid;
        }
        if (height > x)l = mid;
        else if (height < x)r = mid;
        else return mid;
    }
    ll height = 0;
    for (int i = n - 1; i + 1; --i) {
        if (a[i] <= l)break;
        height += a[i] - l;
    }
    if (x > height)return r;
    else return l;
}

int main() {
    scanf("%d%lld", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%lld", a + i);
        ma = max(ma, a[i]);
    }
    sort(a, a + n);
    cout << find(m, 0, ma) << endl;
}
