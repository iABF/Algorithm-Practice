#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

int N, M, A[MAXN];

bool check(int sum_upperbound) {
    int m = M, i = 0;
    while (i < N) {
        int sum = 0;
        while (i < N && sum + A[i] <= sum_upperbound)sum += A[i++];
        if (!m)return false;
        m--;
    }
    return true;
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i)cin >> A[i];
    int l = 0, r = 1e9;
    while (l < r - 1) {
        int mid = (r + l) >> 1;
        if (check(mid))r = mid;
        else l = mid;
    }
    cout << r << endl;
}
