
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <climits>
#include <set>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define LL long long

class Solution {
public:
    vector<int> smallestRange(vector<vector<int> >& nums) {
        typedef vector<int>::iterator vi;
        typedef pair<vi, vi> node;
        struct compareTo {
            bool operator() (const node& n1, const node& n2) const {
                return *n1.first > *n2.first;
            }
        };
        priority_queue<node, vector<node>, compareTo> pq; 
        int lo=INT_MAX, hi=INT_MIN;
        for (int i=0; i < nums.size(); i++) {
            int sz = nums[i].size()-1;
            lo = min(lo, nums[i][0]);
            hi = max(hi, nums[i][sz]);
            pq.push(node(nums[i].begin(), nums[i].end()));
        }
        vector<int> ans;
        ans.push_back(lo); ans.push_back(hi);
        while (true) {
            node p = pq.top();
            pq.pop();
            ++p.first;
            if (p.first == p.second)
                break;
            pq.push(p);
            lo = *pq.top().first;
            hi = max(hi, *p.first);
            if (hi-lo < ans[1]-ans[0]) {
                ans[1] = hi;
                ans[0] = lo;
            }
        }
        return ans;
    }
};
