class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        
        int m = s1.size();
        int n = s2.size();

        if (m + n != s3.size())
            return false;

        vector<bool> dp(n + 1, false);

        dp[0] = true;

        // Using only s2
        for (int j = 1; j <= n; j++) {
            dp[j] = dp[j - 1] &&
                    s2[j - 1] == s3[j - 1];
        }

        for (int i = 1; i <= m; i++) {

            // Using only s1
            dp[0] = dp[0] &&
                    s1[i - 1] == s3[i - 1];

            for (int j = 1; j <= n; j++) {

                int k = i + j - 1;

                bool takeS1 =
                    dp[j] &&
                    s1[i - 1] == s3[k];

                bool takeS2 =
                    dp[j - 1] &&
                    s2[j - 1] == s3[k];

                dp[j] = takeS1 || takeS2;
            }
        }

        return dp[n];
    }
};