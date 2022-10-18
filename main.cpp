#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 50005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;


int L, N, M, D[MAXN] = {0};

bool check(int shortest_jump) {
    int m = M, current_start = D[0];
    for (int i = 1; i <= N + 1; ++i) {
        if (D[i] - current_start < shortest_jump) {
            if (!m)return false;
            m--;
        } else current_start = D[i];
    }
    return true;
}

int main() {
    cin >> L >> N >> M;
    for (int i = 1; i <= N; ++i)cin >> D[i];
    D[N + 1] = L;
    int l = 1, r = L + 1;
    while (l < r - 1) {
        int mid = (r + l) >> 1;
        if (check(mid))l = mid;
        else r = mid;
    }
    cout << l << endl;
}
