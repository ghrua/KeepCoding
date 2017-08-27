#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <climits>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
class Solution {
private:
    bool check(vector<int>& nums, int cuts, int max_sum) {
        int tmp = 0;
        for (int i=0; i < nums.size(); i++) {
            if (nums[i] + tmp > max_sum) {
                tmp = 0;
                cuts--;
            }
            tmp += nums[i];
            if (cuts < 0 || nums[i] > max_sum)
                return false;
        }
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int lo = 0, hi = 0, ans, mid;
        for (int i = 0; i < nums.size(); i++)
            hi += nums[i];
        while(lo <= hi) {
            mid = lo + (hi-lo)/2;
            if (check(nums, m-1, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
}
