#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 2000005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;


char s[15];
int a[15] = {1, 0, 2, 3, 4, 0, 5, 6, 7, 8, 9, 0}, c = 0;


int main() {
    cin >> s;
    for (int i = 0; i < 11; ++i)c += (s[i] - '0') * a[i];
    c %= 11;
    if (c == 10)c = 'X' - '0';
    if (c == s[12] - '0')cout << "Right" << endl;
    else {
        s[12] = c + '0';
        cout << s << endl;
    }
}
