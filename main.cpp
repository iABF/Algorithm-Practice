#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MAXM 1000005
#define MOD 1000000007
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, maxx = 0;
int a[MAXN];
int b[MAXM] = {0};
int cnt[MAXM] = {0};


int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        maxx = max(maxx, a[i]);
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; ++i) {
        if (cnt[a[i]] < 0)continue;
        for (int j = a[i]; j <= maxx; j += a[i])b[j] += cnt[a[i]];
        cnt[a[i]] = -1;
    }
    for (int i = 0; i < n; ++i)cout << b[a[i]] - 1 << endl;
}