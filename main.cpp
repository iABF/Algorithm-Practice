#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int n, a[MAXN], nxt[MAXN], cnt[MAXN] = {0}, num_of_list = 0, ans = INF;

int find_in_nxt(int x, int r) {
    if (!r)return -1;
    int l = 0;
    while (l < r - 1) {
        int mid = (l + r) >> 1;
        if (x < nxt[mid])r = mid;
        else l = mid;
    }
    if (x == nxt[l])return l;
    else return -1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; ++i) {
        int idx = find_in_nxt(a[i], num_of_list);
        if (idx == -1) {
            nxt[num_of_list] = a[i] + 1;
            cnt[num_of_list] = 1;
            num_of_list++;
        } else {
            nxt[idx] = a[i] + 1;
            cnt[idx]++;
            while (nxt[++idx] == a[i] + 1 && cnt[idx] > cnt[idx - 1])swap(cnt[idx], cnt[idx - 1]);
        }
    }
    for (int i = 0; i < num_of_list; ++i)ans = min(ans, cnt[i]);
    cout << ans << endl;
}
