#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 1000000
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int a, b, p, start, cur, ans = 0;
bool prime[MAXN];
int anc[MAXN];
bool vis[MAXN] = {false};


int find(int x) {
    return x == anc[x] ? x : anc[x] = find(anc[x]);
}

int main() {
    cin >> a >> b >> p;
    memset(prime, true, sizeof(prime));
    for (int i = a; i <= b; ++i)anc[i] = i;
    prime[0] = prime[1] = false;
    for (int i = 2; i <= b; ++i)for (int j = 2 * i; j <= b; j += i)prime[j] = false;
    for (int i = p; i <= b; ++i) {
        if (prime[i]) {
            start = a;
            while (start % i)start++;
            cur = start + i;
            while (cur <= b) {
                anc[find(cur)] = anc[find(start)];
                cur += i;
            }
        }
    }
    for (int i = a; i <= b; ++i)if (!vis[find(i)])vis[find(i)] = true, ans++;
    cout << ans << endl;
}
