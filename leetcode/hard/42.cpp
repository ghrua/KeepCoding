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

void show(vector<int>& vec, vector<int> height) {
    for (int i = 0; i < vec.size(); i++) {
        cout << height[vec[i]];
        if (i == vec.size()-1)
            cout << '\n';
        cout << ' ';
    }
}

int trap(vector<int>& height) {
    deque<int> fwdq, bwdq;
    vector<int> fwvec(height.size(), 0), bwvec(height.size(), 0);
    for (int i = 0; i < height.size(); i++) {
        while (!fwdq.empty() && height[fwdq.back()] < height[i])
            fwdq.pop_back();
        fwdq.push_back(i);
        fwvec[i] = fwdq.front();
    }
    for (int i = height.size()-1; i >= 0; i--) {
        while (!bwdq.empty() && height[bwdq.back()] < height[i])
            bwdq.pop_back();
        bwdq.push_back(i);
        bwvec[i] = bwdq.front();
    }
    show(fwvec, height);
    show(bwvec, height);
    int ans = 0;
    for (int i = 0; i < height.size(); i++)
        if (fwvec[i] != i && bwvec[i] != i)
            ans += min(height[fwvec[i]], height[bwvec[i]]) - height[i];
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    vector<int> inputs;
    int t;
    while (cin >> t) {
        inputs.push_back(t);
    }
    cout << trap(inputs) << '\n';
}
