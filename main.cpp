#include <bits/stdc++.h>

#define INF 0x7f7f7f7f
#define MAXN 10005
#define MOD 1000000007
#define ll long long

using namespace std;

class Solution {
public:
    int splitArray(vector<int> &nums, int k) {
        int sum = 0;
        for (auto a: nums)sum += a;
        int l = 0, r = sum;
        while (l < r) {
            int m = (l + r) >> 1;
            if (check(nums, k, m))r = m;
            else l = m + 1;
        }
        return r;
    }

    bool check(vector<int> &nums, int k, int sum) {
        int cur = 0, group = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (cur + nums[i] <= sum)cur += nums[i];
            else {
                cur = nums[i];
                group++;
                if (group > k)return false;
            }
        }
        if (cur)if (group + 1 > k)return false;
        return true;
    }
};
