#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1505
#define MOD 1000000007
#define _PI 3.14159265358979323846
#define ll long long
using namespace std;

string gen() {
    char c;
    string ans;
    int num;
    while (cin >> c) {
        if (c == '[') {
            cin >> num;
            string s = gen();
            while (num--)ans += s;
        } else if (c == ']')return ans;
        else ans += c;
    }
}

int main() {
    cout << gen() << endl;
}
