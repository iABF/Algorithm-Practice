#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 1000000007
#define BASE 69
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

char c;
string name;
ll cur_father = 0, name_hash;
unordered_map<ll, ll> f;

ll str_encode(string s) {
    ll res = 0;
    for (char i: s)res = res * BASE + i - 'A';
    return res;
}

string str_decode(ll x) {
    string res;
    int cnt = 6;
    while (cnt--) {
        res.push_back(x % BASE + 'A');
        x /= BASE;
    }
    reverse(res.begin(), res.end());
    return res;
}

ll find(ll x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

int main() {
    while (true) {
        cin >> name;
        if (name[0] == '$')return 0;
        c = name[0];
        name = name.substr(1);
        name_hash = str_encode(name);
        if (!f.count(name_hash))f[name_hash] = name_hash;
        if (c == '#')cur_father = name_hash;
        else if (c == '+')f[find(name_hash)] = find(cur_father);
        else cout << name << ' ' << str_decode(find(name_hash)) << endl;
    }
}
