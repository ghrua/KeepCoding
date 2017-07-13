#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
int procedure (vector<int> num, int lo, int hi) {
    int mid;
    while (lo < hi) {
        mid = (lo+hi) >> 1;
        if (num[mid] > num[hi])
            lo = mid+1;
        else if (num[mid] < num[hi])
            hi = mid;
        else
            hi--;
    }
    return num[lo];
}
int findMin(vector<int> &nums) {
    return procedure(nums, 0, nums.size()-1)
}
int main() {
    ios_base::sync_with_stdio(false);
}
