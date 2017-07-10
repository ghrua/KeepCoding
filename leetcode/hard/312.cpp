#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
void procedure(vector<vector<int> >& dp, vector<int>& vec, int it, int n) {
    if (it >= n)
        return;
    for (int i=1; i <= n-it; i++) {
        int end = i+it;
        for (int k = i; k <= end; k++)
            dp[i][end] = max(dp[i][end], dp[i][k-1]+dp[k+1][end]+vec[i-1]*vec[end+1]*vec[k]);
    }
    procedure(dp, vec, it+1, n);
}
int maxCoins(vector<int>& nums) {
    nums.insert(nums.begin(), 1);
    nums.push_back(1);
    vector<vector<int> > dp(nums.size()+2, vector<int>(nums.size()+2, 0));
    procedure(dp, nums, 0, nums.size()-2);
    return dp[1][nums.size()-2];
}
int main() {
    ios_base::sync_with_stdio(false);
    vector<int> nums;
    int n, t;
    cin >> n;
    while (n--) {
        cin >> t;
        nums.push_back(t);
    }

    cout << maxCoins(nums) << '\n';
}
