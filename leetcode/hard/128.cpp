#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <utility>
#include <climits>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
#define LL long long

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> us(nums.begin(), nums.end());
        int ans = 0;
        for (auto it : us) {
            if (!us.count(it-1)) {
                int jt = it;
                while (us.count(jt)) jt++;
                ans = max(ans, jt-it);
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

}
