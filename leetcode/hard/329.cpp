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
    struct node {
        int x, y, val;
    };
    struct cmp {
        bool operator() (node n1, node n2) {
            return n1.val > n2.val;
        }
    };
public:
    int longestIncreasingPath(vector<vector<int> >& matrix) {
        if (!matrix.size())
            return 0;
        int row = matrix.size(), col = matrix[0].size();
        vector<vector<int> > vec(row, vector<int>(col, 1));
        priority_queue<node, vector<node>, cmp> pq;
        int dir[4][2] = {-1, 0, 1, 0, 0, 1, 0, -1};
        int optimal = 1;
        for (int i=0; i < row; i++)
            for (int j=0; j < col; j++) {
                node tn;
                tn.x = i; tn.y = j; tn.val = matrix[i][j];
                pq.push(tn);
            }
        while (!pq.empty()) {
            node top = pq.top(); pq.pop();
            for (int i=0; i < 4; i++) {
                int x = top.x+dir[i][0], y = top.y+dir[i][1];
                if (x < 0 || x >= row || y < 0 || y >= col || matrix[top.x][top.y] <= matrix[x][y])
                    continue;
                vec[top.x][top.y] = max(vec[top.x][top.y], vec[x][y]+1);
            }
            if (vec[top.x][top.y] > optimal)
                optimal++;
        }
        return optimal;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
}
