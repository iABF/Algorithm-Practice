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
} s[1005];

bool check(student &x, student &y) {
    if (abs(x.a - y.a) > 5)return false;
    if (abs(x.b - y.b) > 5)return false;
    if (abs(x.c - y.c) > 5)return false;
    return (abs(x.a + x.b + x.c - y.a - y.b - y.c) <= 10);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; ++i)cin >> s[i].name >> s[i].a >> s[i].b >> s[i].c;
    for (int i = 0; i < N; ++i)
        for (int j = i + 1; j < N; ++j)
            if (check(s[i], s[j]))
                cout << s[i].name << ' ' << s[j].name << endl;
}
