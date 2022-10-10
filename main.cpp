#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 100005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

bool prime[MAXN] = {false};
int n, a;

void find_prime() {
    for (int i = 2; i < MAXN; ++i)prime[i] = true;
    for (int i = 2; i * 2 < MAXN; ++i)
        if (prime[i])
            for (int j = i * 2; j < MAXN; j += i)
                prime[j] = false;
}

int main() {
    find_prime();
    cin >> n;
    while (n--) {
        cin >> a;
        if (prime[a]) {
            cout << a;
            if (!n)cout << endl;
            else cout << ' ';
        }
    }
}
