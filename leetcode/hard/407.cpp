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
    typedef pair<int, int> node;
    struct compare {
        bool operator() (node& n1, node& n2) {
            return n1.first > n2.first;
        }
    };
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() == 0)
            return 0;
        int dir[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
        int ans = 0, max_height = 0;
        priority_queue<node, vector<node>, compare> pq;
        int r = heightMap.size(), c = heightMap[0].size();
        vector<vector<bool> > visited(r, vector<bool>(c, 0));
        for (int i=0; i < r; i++)
            for (int j=0; j < c; j++) {
                if (i == 0 || j == 0 || i == r-1 || j == c-1) {
                    pq.push(node(heightMap[i][j], i*c+j));
                    visited[i][j] = 1;
                }
            }
        while(!pq.empty()) {
            node tmp = pq.top();
            pq.pop();
            int height = tmp.first, tc = tmp.second % c, tr = tmp.second / c;
            max_height = max(max_height, height);
            for (int i=0; i < 4; i++) {
                int x = tr + dir[i][0], y = tc + dir[i][1];
                if (x < 0 || x >= r || y < 0 || y >= c || visited[x][y])
                    continue;
                if (heightMap[x][y] < max_height)
                    ans += max_height - heightMap[x][y];
                visited[x][y] = 1;
                pq.push(node(heightMap[x][y], x*c+y));
            }
        }
        return ans;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
}
