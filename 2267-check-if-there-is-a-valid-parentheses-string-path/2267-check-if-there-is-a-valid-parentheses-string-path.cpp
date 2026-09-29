class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int len = m + n - 1;

        // Valid parentheses string must have even length.
        if (len % 2 == 1)
            return false;

        // Must start with '(' and end with ')'.
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // dp[i][j][b] = can we reach (i,j) with balance b?
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(len + 1, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int prev = 0; prev <= len; ++prev) {
                    bool reachable = false;

                    if (i > 0 && dp[i - 1][j][prev])
                        reachable = true;

                    if (j > 0 && dp[i][j - 1][prev])
                        reachable = true;

                    if (!reachable)
                        continue;

                    int balance = prev + change;

                    if (balance >= 0 && balance <= len)
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};