class Solution {
public:
    void procedure (int it, int n, vector<int>& board, int& ans) {
        if (it > n) {
            ans++;
            return;
        }
        for (int i=1; i <= n; i++) {
            board[it] = i;
            bool tag = true;
            for (int k=1; k < it; k++)
                if (board[k] == board[it] || abs(board[k]-board[it]) == it-k) {
                    tag = false;
                    break;
                }
            if (tag)
                procedure(it+1, n, board, ans);
        }
    }
    int totalNQueens (int n) {
        vector<int> board(n+1);
        int ans=0;
        procedure(1, n, board, ans);
        return ans;
    }
};
