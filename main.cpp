#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

int N;

struct student {
    string name;
    int a;
    int b;
    int c;
    int idx;
} s[1005];

bool cmp(const student &x, const student &y) {
    int xx = x.a + x.b + x.c, yy = y.a + y.b + y.c;
    if (xx == yy)return x.idx < y.idx;
    return xx > yy;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        s[i].idx = i;
        cin >> s[i].name >> s[i].a >> s[i].b >> s[i].c;
    }
    sort(s, s + N, cmp);
    cout << s[0].name << ' ' << s[0].a << ' ' << s[0].b << ' ' << s[0].c << endl;
}
