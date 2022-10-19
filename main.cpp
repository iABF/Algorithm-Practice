#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 1000000
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n-1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, a, ans = 0;
vector<int> q;

int find(int l, int r, int x) {
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (x > q[mid])l = mid;
        else if (x < q[mid])r = mid;
        else return mid;
    }
    if (q[l] < x)return r;
    return l;
}

int main() {
    cin >> n;
    while (n--) {
        cin >> a;
        if (q.empty()) {
            ans += a;
            q.push_back(a);
        } else {
            int pos = find(0, q.size(), a), cur = INF;
            if (pos)cur = abs(q[pos - 1] - a);
            if (pos < q.size())cur = min(cur, abs(q[pos] - a));
            ans += cur;
            q.insert(q.begin() + pos, a);
        }
    }
    cout << ans << endl;
}
