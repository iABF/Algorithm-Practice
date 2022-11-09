#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 80112002
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, m, degree[MAXN] = {0}, num_of_stops, s, st, ed;
set<int> stops;
bool mp[MAXN][MAXN] = {false};

int toposort() {
    int ans = 0;
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; ++i)if (!degree[i])q.push(make_pair(i, 1));
    while (!q.empty()) {
        auto t = q.front();
        q.pop();
        int cur = t.first, level = t.second;
        ans = max(ans, level);
        for (int i = 1; i <= n; ++i)
            if (mp[cur][i]) {
                mp[cur][i] = false;
                if (!(--degree[i]))q.push(make_pair(i, level + 1));
            }
    }
    return ans;
}

int main() {
    cin >> n >> m;
    while (m--) {
        st = 0;
        stops.clear();
        cin >> num_of_stops;
        while (num_of_stops--) {
            cin >> s;
            if (!st)st = s;
            stops.insert(s);
        }
        ed = s;
        for (int i = st; i <= ed; ++i)
            if (!stops.count(i))
                for (auto j: stops)
                    if (!mp[i][j])
                        mp[i][j] = true, degree[j]++;
    }
    cout << toposort() << endl;
}