#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int q, n, src[MAXN], dst[MAXN];
stack<int> s;

int main() {
    cin >> q;
    while (q--) {
        cin >> n;
        int pos = 0;
        for (int i = 0; i < n; ++i)cin >> src[i];
        for (int i = 0; i < n; ++i)cin >> dst[i];
        for (int i = 0; i < n; ++i) {
            s.push(src[i]);
            while (pos < n && !s.empty() && s.top() == dst[pos]) {
                pos++;
                s.pop();
            }
        }
        if (pos == n)cout << "Yes" << endl;
        else cout << "No" << endl;
        while (!s.empty())s.pop();
    }
}
