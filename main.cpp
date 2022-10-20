#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 1000000
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n-1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

struct Node {
    int l = 0, r = 0;
} node[MAXN];
int n, ans = 1;

void dfs(int num, int depth) {
    if (depth > ans)ans = depth;
    if (node[num].l)dfs(node[num].l, depth + 1);
    if (node[num].r)dfs(node[num].r, depth + 1);
}


int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)cin >> node[i].l >> node[i].r;
    dfs(1, 1);
    cout << ans << endl;
}
