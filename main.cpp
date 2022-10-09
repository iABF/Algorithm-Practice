#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

bool prime[105] = {false};
const int p[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
char s[105];
int word[27] = {0}, n;

int main() {
    for (int i = 0; i < 25; ++i)prime[p[i]] = true;
    cin >> s;
    n = strlen(s);
    for (int i = 0; i < n; ++i)word[s[i] - 'a']++;
    int l = INF, r = -1;
    for (int i = 0; i < 26; ++i) {
        if (word[i] && (word[i] < l))l = word[i];
        if (word[i] > r)r = word[i];
    }
    if (prime[r - l])cout << "Lucky Word" << endl << r - l << endl;
    else cout << "No Answer" << endl << 0 << endl;

}
