#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 10005
#define MOD 1000000007
#define BASE 131
#define _PI 3.14159265358979323846
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

map<string, int> mp;
string str;
int n, op, score;

int main() {
    cin >> n;
    while (n--) {
        cin >> op;
        if (op == 4)cout << mp.size() << endl;
        else {
            cin >> str;
            if (op == 1) {
                cin >> score;
                mp[str] = score;
                cout << "OK" << endl;
            } else if (op == 2) {
                map<string, int>::iterator it;
                if ((it = mp.find(str)) != mp.end())cout << it->second << endl;
                else cout << "Not found" << endl;
            } else if (op == 3) {
                if (mp.erase(str))cout << "Deleted successfully" << endl;
                else cout << "Not found" << endl;
            }
        }
    }
}
