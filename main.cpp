#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 1000000007
#define ll long long
using namespace std;

int n, k;
int a[MAXN];
int ans[2][MAXN];

struct MonoQueue {
    int b[MAXN] = {0};
    int l = 1, r = 1;


    void push(int x) {
        b[++r] = x;
    }

    int tail() {
        return b[r];
    }

    int head() {
        return b[l];
    }

    bool check() {
        return l <= r;
    }
} big, small;

void print(int x) {
    for (int i = k; i < n; ++i)printf("%d ", ans[x][i - k]);
    printf("%d\n", ans[x][n - k]);
}

void generate_small() {
    for (int i = 1; i <= n; ++i) {
        while (small.check() && a[small.tail()] >= a[i])small.r--;
        small.push(i);
        if (small.head() <= i - k)small.l++;
        if (i >= k)ans[0][i - k] = a[small.head()];
    }
}

void generate_big() {
    for (int i = 1; i <= n; ++i) {
        while (big.check() && a[big.tail()] <= a[i])big.r--;
        big.push(i);
        if (big.head() <= i - k)big.l++;
        if (i >= k)ans[1][i - k] = a[big.head()];
    }
}

int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i)scanf("%d", a + i);
    generate_small();
    generate_big();
    print(0);
    print(1);
}