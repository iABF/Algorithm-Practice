#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 2000005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

int n, k, a[MAXN];

priority_queue<pair<int, int>> q;

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        q.push(make_pair(a[i], i));
        if (i >= k - 1) {
            while (q.top().second <= i - k)q.pop();
            cout << q.top().first << endl;
        }
    }
}
