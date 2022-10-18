#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int m, n, school[MAXN], s;
ll ans = 0;

int find(int x) {
    int l = 0, r = m;
    while (r - l > 1) {
        int mid = (r + l) >> 1;
        if (school[mid] == x)return 0;
        else if (school[mid] > x)r = mid;
        else l = mid;
    }
    if (l < m - 1)return min(abs(x - school[l]), abs(x - school[l + 1]));
    else return abs(x - school[l]);
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; ++i)cin >> school[i];
    sort(school, school + m);
    while (n--) {
        cin >> s;
        ans += find(s);
    }
    cout << ans << endl;
}
