#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1000005
#define MOD 10000
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;


double a, b, c, d;
vector<double> ans;

double cal(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

void find(double l, double r) {
    while (r - l > 1e-6) {
        double m = (l + r) / 2;
        double L = cal(l), M = cal(m), R = cal(r);
        if (abs(M) < 1e-6){
            ans.push_back(m);
            return;
        }
        else if (L * M < 0)r = m;
        else if (R * M < 0)l = m;
    }
    ans.push_back(l);
}

int main() {
    cin >> a >> b >> c >> d;
    for (double i = -100; i <= 100; i += 1)if (abs(cal(i)) < 1e-6)ans.push_back(i);
    for (double i = -100; i < 100; i += 1) {
        if (ans.size() == 3)break;
        if (cal(i) * cal(i + 1) < 0)find(i, i + 1);
    }
    sort(ans.begin(), ans.end());
    printf("%.2lf %.2lf %.2lf\n", ans[0], ans[1], ans[2]);
}
