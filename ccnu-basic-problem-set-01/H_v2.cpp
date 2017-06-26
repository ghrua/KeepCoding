#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <set>
#include <vector>
#include <queue>
using namespace std;
#define LL long long
string board[3];

bool win(char ch) {
    for (int i=0; i < 3; i++) {
        bool tag = true;
        for (int k=0; k < 3; k++)
            if (board[i][k] != ch)
                tag = false;
        if (tag)
            return true;
    }
    for (int i=0; i < 3; i++) {
        bool tag = true;
        for (int k=0; k < 3; k++)
            if (board[k][i] != ch)
                tag = false;
        if (tag)
            return true;
    }
    if (board[0][0] == ch && board[1][1] == ch && board[2][2] == ch) return true;
    if (board[2][0] == ch && board[1][1] == ch && board[0][2] == ch) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    int cnt_x=0, cnt_0=0;
    for (int i=0; i < 3; i++)
        cin >> board[i];
    for (int i=0; i < 3; i++)
        for (int k=0; k < 3; k++) {
            if (board[i][k] == 'X')
                cnt_x++;
            else if (board[i][k] == '0')
                cnt_0++;
        }
    bool win1=win('X'), win2=win('0');
    if ((win1 && win2) || (win1 && cnt_x-cnt_0 != 1) || (win2 && cnt_0 != cnt_x)
             || cnt_x-cnt_0 > 1 || cnt_0 > cnt_x)
        cout << "illegal\n";
    else if (win1)
        cout << "the first player won\n";
    else if (win2)
        cout << "the second player won\n";
    else if (cnt_0+cnt_x == 9)
        cout << "draw\n";
    else if (cnt_0 == cnt_x) 
        cout << "first\n";
    else if (cnt_0 < cnt_x)
        cout << "second\n";
    return 0;
}
