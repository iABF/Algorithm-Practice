#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 10005
#define MOD 1000000007
#define ll long long
using namespace std;

int N, m1, m2, S, cur = 2;
double p[30005] = {0};

double check(int a) {
    double ans = 0;
    for (int i = 2; i < cur; ++i) {
        if (p[i] > 0) {
            int num = 0;
            while (a % i == 0) {
                a /= i;
                num++;
            }
            if (num > 0)ans = max(ans, p[i] / num);
            else return -1;
        }
    }
    return ans;
}

int main() {
    cin >> N >> m1 >> m2;
    while (m1 > 1) {
        while (m1 % cur == 0) {
            m1 /= cur;
            p[cur]++;
        }
        cur++;
    }
    double ans = -1;
    for (int i = 2; i < cur; ++i)p[i] *= m2;
    for (int i = 0; i < N; ++i) {
        cin >> S;
        double tmp = check(S);
        if (tmp == -1)continue;
        else if (ans == -1)ans = tmp;
        else ans = min(ans, tmp);
    }
    cout << ceil(ans) << endl;
}