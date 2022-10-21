#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 105
#define MOD 1000000
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n-1] << endl
#define PRINT(a) cout << a << endl
using namespace std;


struct Node {
    int l;
    int r;
    int f;
    int value;
} node[MAXN];
int n, ans = 0, final = INF;

void dfs(int nde, int step, int from_where) {
    ans += step * node[nde].value;
    if (node[nde].l && node[nde].l != from_where)dfs(node[nde].l, step + 1, nde);
    if (node[nde].r && node[nde].r != from_where)dfs(node[nde].r, step + 1, nde);
    if (node[nde].f && node[nde].f != from_where)dfs(node[nde].f, step + 1, nde);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i].value >> node[i].l >> node[i].r;
        node[node[i].l].f = node[node[i].r].f = i;
    }
    for (int i = 0; i < n; ++i, ans = 0) {
        dfs(i, 0, -1);
        final = min(final, ans);
    }
    cout << final << endl;
}
