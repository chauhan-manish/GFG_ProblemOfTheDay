class Solution {
  public:
    long long int numberOfPaths(int m, int n){
        // code here
        long long dp[m][n];
        long long mod = 1000000007;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                }
            }
        }
        dp[0][0] = 0;
        return dp[m - 1][n - 1];
    }
};