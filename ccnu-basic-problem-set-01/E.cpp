/*
This program is the first try of problem E and got a "Memory Limit Exceeded" error.
*/
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
struct node {
    int x, y, n0, n2, n5;
    vector<char> path;
};
struct mycmp {
	bool operator() (const node &lhs, const node &rhs) const {
        int a = min(rhs.n2, rhs.n5), b = min(lhs.n2, lhs.n5);
        if (rhs.n0)
            a = 1;
        if (lhs.n0)
            b = 1;
        if (a < b)
            return true;
        else if (a == b && (rhs.x+rhs.y) > (lhs.x+lhs.y))
            return true;
        else
            return false;
	}
};
priority_queue<node, vector<node>, mycmp> pq;
int matrix[1001][1001]={0};

int convert (int num, int base) {
    int ans = 0;
    while (num % base == 0) {
        num /= base;
        ans++;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, i, j;
    cin >> n;
    for (i=1; i <= n; i++)
        for (j=1; j <= n; j++)
            cin >> matrix[i][j];
    int start = matrix[1][1];
    node init;
    init.x = init.y = 1;
    if (start) {
        init.n0 = 0; init.n2 = convert(start, 2); init.n5 = convert(start, 5);
    }
    else
        init.n0 = 1;
    pq.push(init);
    while(!pq.empty()) {
        node t = pq.top();
        pq.pop();
        if (t.x == n && t.y == n) {
            if (t.n0)
                cout << "1\n";
            else
                cout << min(t.n2, t.n5) << '\n';
            int len = t.path.size();
            for (i=0; i < len; i++)
                cout << t.path[i];
            cout << '\n';
            return 0;
        }
        node left=t, right=t;
        if (t.x < n) {
            left.x++; left.path.push_back('D');
            int tmp = matrix[left.x][left.y];
            if (!tmp || t.n0)
                left.n0 = 1;
            else {
                left.n2 += convert(tmp, 2);
                left.n5 += convert(tmp, 5);
            }
            pq.push(left);
        }
        if (t.y < n) {
            right.y++; right.path.push_back('R');
            int tmp = matrix[right.x][right.y];
            if (!tmp || t.n0)
                right.n0 = 1;
            else {
                right.n2 += convert(tmp, 2);
                right.n5 += convert(tmp, 5);
            }
            pq.push(right);
        }
    }
}
