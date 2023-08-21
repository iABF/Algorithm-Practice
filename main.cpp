#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 50005
#define MOD 1000000007
#define ll long long

using namespace std;

int n, fa;
int clr[MAXN];

struct {
    vector<int> l;
    bool isLeaf = true;
} nxt[MAXN];
int f[MAXN];

void dfs(int cur) {
    if (nxt[cur].isLeaf) {
        f[cur] = 1;
        return;
    }
    dfs(nxt[cur].l[0]);
    dfs(nxt[cur].l[1]);
    if (clr[cur] == 1)f[cur] = f[nxt[cur].l[0]] + f[nxt[cur].l[1]];
    else f[cur] = f[nxt[cur].l[0]] ^ f[nxt[cur].l[1]];

}

int main() {
    cin >> n;
    memset(f, 1, sizeof(f));
    for (int i = 2; i <= n; ++i) {
        cin >> fa;
        nxt[fa].isLeaf = false;
        nxt[fa].l.push_back(i);
    }
    for (int i = 1; i <= n; ++i)cin >> clr[i];
    dfs(1);
    cout << f[1] << endl;
}


// 开始时间：
// 完成时间：2023年8月21日21:53:22
// 耗时：

// 思路：