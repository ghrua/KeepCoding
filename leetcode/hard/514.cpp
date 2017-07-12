#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
int findRotateSteps(string ring, string key) {
    const int N = 105;
    int row = key.size(), col = ring.size();
    key.insert(0, " ");
    ring.insert(0, " ");
    int f[N][N]={0};
    for (int i=1; i <= col; i++)
        if (key[1] == ring[i])
            f[1][i] = min(i-1, 1-i+col)+1;
        else
            f[1][i] = -1;
    for (int i=2; i <= row; i++) {
        for (int k=1; k <= col; k++) {
            if (key[i] != ring[k]) {
                f[i][k] = -1;
                continue;
            }
            f[i][k] = 10500;
            for (int m=1; m <= col; m++)
                if (f[i-1][m] != -1)
                    f[i][k] = min(f[i][k],1+f[i-1][m]+min(abs(m-k), -abs(k-m)+col));
        }
    }
    int ans = 10500;
    for (int i=1; i <= col; i++) {
        if (f[row][i] == -1)
            continue;
        ans = min(f[row][i], ans);
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    string s1, s2;
    cin >> s1 >> s2;
    cout << findRotateSteps(s1, s2) << '\n';
}
