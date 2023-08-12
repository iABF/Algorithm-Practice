#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
#define ll long long

int n;
int a[MAXN];
int x, y;
vector<int> v[MAXN];
bool vis[MAXN] = {false};

int ans = 0;


bool check(ll p, ll q) {
    ll t = lround(sqrt((long double) (p * q)));
    if (t * t == p * q)return true;
    return false;
}

void dfs(int cur, int num) {
    if (cur == n + 1) {
        ans = max(ans, num);
        return;
    }
    dfs(cur + 1, num);
    if (!v[cur].empty() && !vis[cur]) {
        for (auto k: v[cur]) {
            if (!vis[k]) {
                vis[cur] = true;
                vis[k] = true;
                dfs(cur + 1, num + 2);
                vis[cur] = false;
                vis[k] = false;
            }
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
        cin >> x >> y;
        if (check(a[x], a[y])) {
            if (x < y)v[x].push_back(y);
            else v[y].push_back(x);
        }

    }
    dfs(1, 0);
    cout << ans << endl;
}