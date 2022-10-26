#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 1000000007
#define BASE 131
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, m, f[MAXN], r, s, enemy[MAXN] = {0}, ans = 0;
bool vis[MAXN] = {false};
char op;

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void merge(int x, int y) {
    f[find(x)] = find(y);
}


int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)f[i] = i;
    while (m--) {
        cin >> op >> r >> s;
        if (op == 'E') {
            if (enemy[r])merge(s, enemy[r]);
            else enemy[r] = s;
            if (enemy[s])merge(r, enemy[s]);
            else enemy[s] = r;
        } else merge(s, r);
    }
    for (int i = 1; i <= n; ++i)if (!vis[find(i)])ans++, vis[find(i)] = true;
    cout << ans << endl;
}
