#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

string small, big;
int ans = 0, pos;

int main() {
    getline(cin, small);
    getline(cin, big);
    transform(small.begin(), small.end(), small.begin(), ::tolower);
    transform(big.begin(), big.end(), big.begin(), ::tolower);

    int i = 0;
    while (i < big.length()) {
        while (i != big.length() && big[i] == ' ')i++;
        bool k = true;
        for (int j = 0; j < small.length(); ++j, ++i)
            if (i == big.length() || big[i] != small[j]) {
                k = false;
                break;
            }
        if (k && (i == big.length() || big[i] == ' ')) {
            if (!ans)pos = i - small.length();
            ans++;
        }
        while (i != big.length() && big[i] != ' ')i++;
    }

    if (!ans)cout << -1 << endl;
    else cout << ans << " " << pos << endl;
}
