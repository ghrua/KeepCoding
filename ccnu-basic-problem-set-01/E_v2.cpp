#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;
#define LL long long
const int N = 1005;
char dir[N][N][2]={0};
int dp[N][N][2]={0}, matrix[N][N]={0};
int convert (int num, int base) {
    int ans = 0;
    if (num == 0)
        return 1;
    while (num % base == 0) {
        ans++;
        num /= base;
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n, zero=-1;
    cin >> n;
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
                zero = i;
            dp[i][j][0] = convert(matrix[i][j], 2);
            dp[i][j][1] = convert(matrix[i][j], 5);
        }
    for (int i=0; i < n; i++)
        for (int j=0; j < n; j++)
            for (int k=0; k < 2; k++) {
                if (i==0 && j==0)
                    continue;
                if (i == 0) {
                    dp[i][j][k] += dp[i][j-1][k];
                    dir[i][j][k] = 'R';
                }
                else if (j == 0) {
                    dp[i][j][k] += dp[i-1][j][k];
                    dir[i][j][k] = 'D';
                }
                else {
                    if (dp[i-1][j][k] < dp[i][j-1][k]) {
                        dp[i][j][k] += dp[i-1][j][k];
                        dir[i][j][k] = 'D';
                    }
                    else {
                        dp[i][j][k] += dp[i][j-1][k];
                        dir[i][j][k] = 'R';
                    }
                }
            }
    int ans = min(dp[n-1][n-1][0], dp[n-1][n-1][1]);
    if (zero != -1 && ans > 1) {
        cout << "1\n";
        for (int i=0; i < zero; i++) cout << 'D';
        for (int i=0; i < n-1; i++) cout << 'R';
        for (int i=zero; i < n-1; i++) cout << 'D';
        cout << '\n';
    }
    else {
        cout << ans << '\n';
        char p[2*N]={0};
        int index = 0, k = (dp[n-1][n-1][0] == ans ? 0 : 1), i=n-1, j=n-1;
        while (i || j) {
            p[index++] = dir[i][j][k];
            if (dir[i][j][k] == 'R')
                j--;
            else
                i--;
        }
        for (i=index-1; i >= 0; i--)
            cout << p[i];
        cout << '\n';
    }
}
