#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

string s;
int num[26] = {0}, m = 0;

int main() {
    for (int i = 0; i < 4; ++i) {
        getline(cin, s);
        for (char c: s)
            if (c >= 'A' && c <= 'Z') {
                num[c - 'A']++;
                m = num[c - 'A'] > m ? num[c - 'A'] : m;
            }
    }
    for (int i = m; i >= 1; --i) {
        for (int j = 0; j < 26; ++j) {
            if (num[j] >= i)cout << '*';
            else cout << ' ';
            if (j == 25)cout << endl;
            else cout << ' ';
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (i == 25)cout << 'Z' << endl;
        else cout << char(i + 'A') << ' ';
    }
}
