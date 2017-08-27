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
public:
    string minWindow(string s, string t) {
        int table[256] = {0};
        for (auto ch : t) table[ch]++;
        int tag = t.size(), head, begin=0, end=0, d=INT_MAX;
        while (end < s.size()) {
            if (table[s[end++]]-- > 0) tag--;
            while (tag == 0) {
                if (d < end-begin)
                    d = end-(head=begin);
                if (table[s[begin++]]-- > 0) tag++;
            }
        }
        return d == INT_MAX ? "" : s.substr(head, end);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
}
