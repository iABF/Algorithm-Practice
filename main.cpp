#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

string s;
int n;

string revert_and_strip(string num) {
    if (num == "0")return num;
    reverse(num.begin(), num.end());
    while (num[0] == '0')num = num.substr(1, num.length() - 1);
    while (num[num.length() - 1] == '0')num = num.substr(0, num.length() - 1);
    return num;
}

int main() {
    cin >> s;
    if ((n = s.find('.')) > 0)
        cout << revert_and_strip(s.substr(0, n)) << "." << revert_and_strip(s.substr(n + 1, s.length() - n - 1));
    else if ((n = s.find('/')) > 0)
        cout << revert_and_strip(s.substr(0, n)) << "/" << revert_and_strip(s.substr(n + 1, s.length() - n - 1));
    else if (s[s.length() - 1] == '%')
        cout << revert_and_strip(s.substr(0, s.length() - 1)) << "%" << endl;
    else cout << revert_and_strip(s) << endl;
}
