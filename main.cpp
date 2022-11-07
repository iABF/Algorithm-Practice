#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 1005
#define MAXM 50005
#define MOD 80112002
#define ll long long
#define VPRINT(a, n) for(int i = 0; i < n - 1; ++i) cout << a[i] <<' '; cout << a[n - 1] << endl
#define PRINT(a) cout << a << endl
using namespace std;

int n, ans_vec[MAXN], pos = 0;
vector<int> startswith[26], start_candidate, end_candidate;
int start_count[26] = {0}, end_count[26] = {0};
string word[MAXN];
bool vis[MAXN] = {false};

void dfs(int num, int cur) {
    ans_vec[num - 1] = cur;
    vis[cur] = true;
    if (num == n) {
        for (int i = 0; i < n - 1; ++i)cout << word[ans_vec[i]] << '.';
        cout << word[ans_vec[n - 1]] << endl;
        exit(0);
    }
    for (auto i: startswith[word[cur].back() - 'a'])if (!vis[i])dfs(num + 1, i);
    vis[cur] = false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> word[i];
    sort(word, word + n);
    for (int i = 0; i < n; ++i) {
        startswith[word[i][0] - 'a'].push_back(i);
        start_count[word[i][0] - 'a']++;
        end_count[word[i].back() - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (start_count[i] - end_count[i] == 1)start_candidate.push_back(i);
        if (start_count[i] - end_count[i] == -1)end_candidate.push_back(i);
    }
    if (start_candidate.size() == end_candidate.size() && start_candidate.size() < 2) {
        if (!start_candidate.empty()) {
            while (word[pos][0] - 'a' != start_candidate[0])pos++;
            while (pos < n && !word[pos].empty() && word[pos][0] - 'a' == start_candidate[0])dfs(1, pos++);
        } else dfs(1, 0);
    }
    cout << "***" << endl;
}
