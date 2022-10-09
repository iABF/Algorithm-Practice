#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 2000005
#define MOD 10007
#define _PI 3.14159265358979323846
using namespace std;

bool p[100005] = {false};
int L, cnt = 0;

void prime() {
    for (int i = 2; i < 100000; i++)
        p[i] = true;
    for (int i = 2; i < 100000; i++)
        if (p[i])
            for (int j = i * 2; j < 100000; j += i)
                p[j] = false;

}

int main() {
    cin >> L;
    prime();
    for (int i = 2; i < 100000; ++i) {
        if (p[i]) {
            L -= i;
            if (L >= 0) {
                cout << i << endl;
                cnt += 1;
            } else {
                cout << cnt << endl;
                break;
            }
        }
    }
}
